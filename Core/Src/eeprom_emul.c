
/*
 * Funzioni per l'emulazione della eeprom sulla flash del microcontrollore
 *
 * */
#include "main.h"
#include "eeprom_emul.h"

#include "eeprom_emul.h"
#include <string.h>

#define   EE_USED_FLASH_PAGE    448
#define   EE_USED_RAM_BYTE      1024	//dimensione della variabile d'appoggio per il salvataggio dei dati che si vogliono
										//scrivere sulla flash, anche nella RAM

#define   EE_SIZE              2048	//dimensione in bytes di una pagina della flash (2Kb)
#define   EE_BASE_ADDR 			0x080E0000	//indirizzo base della eeprom emulata
//#define   EE_BASE_ADDR 		   0x0807F800
#define   EE_FLASH_BANK        FLASH_BANK_2

#if (EE_USED_RAM_BYTE > 0)
uint8_t ee_ram[EE_USED_RAM_BYTE];
#endif


bool ee_init(void)
{
#if (EE_USED_RAM_BYTE > 0)
  return ee_read(0, EE_USED_RAM_BYTE, NULL);
#else
  return true;
#endif
}

/*
 * Funzione per la formattazione della "zona eeprom" della flash.
 *
 * @param keepRamData: parametro che permette di mantenere o cancellare anche il contenuto del vettore di appoggio ee_ram
 * */

bool ee_format(bool keepRamData)
{
  uint32_t error;

  HAL_FLASH_Unlock();
  FLASH_EraseInitTypeDef flashErase;

/*procedura di cancellazione 1*/

  flashErase.NbPages = 1;
  flashErase.Page = EE_USED_FLASH_PAGE;
  flashErase.TypeErase = FLASH_TYPEERASE_PAGES;
  flashErase.Banks = EE_FLASH_BANK;

  if (HAL_FLASHEx_Erase(&flashErase, &error) == HAL_OK)
  {
    HAL_FLASH_Lock();
    if (error != 0xFFFFFFFF)
      return false;
    else
    {

 /*Se keepRamData e' false, allora vengono cancellati anche i dati (del buffer ee_ram) nella RAM*/
#if (EE_USED_RAM_BYTE > 0)
      if (keepRamData == false)
        memset(ee_ram, 0xFF, EE_USED_RAM_BYTE);
#endif
      return true;
    }
  }
  HAL_FLASH_Lock();
  return false;
}

/*
 * Funzione di lettura della flash: nel caso di utilizzo del buffer di appoggio nella RAM, il contenuto della flash viene copiato
 * sia nel buffer "data" sia nella ram (nel buffer ee_ram)
 *
 * @param startVirtualAddress: indirizzo base della "zona eeprom" nella flash
 * @param len: numero di byte da leggere
 * @param data: puntatore all'array in cui si vuole copiare il contenuto della flash eeprom
 *
 * */

bool ee_read(uint32_t startVirtualAddress, uint32_t len, uint8_t* data)
{
  if ((startVirtualAddress + len) > EE_SIZE)
    return false;
  for (uint32_t i = startVirtualAddress; i < len + startVirtualAddress; i++)
  {
    if (data != NULL)
    {
      *data = (*(__IO uint8_t*) (i + EE_BASE_ADDR));
      data++;
    }
#if (EE_USED_RAM_BYTE > 0)
    if (i < EE_USED_RAM_BYTE)
      ee_ram[i] = (*(__IO uint8_t*) (i + EE_BASE_ADDR));
#endif
  }
  return true;
}

/*
 * Funzione di programmazione della flash in modalità DOUBLEWORD, ovvero, 64 bit alla volta.
 * */

bool ee_write(uint32_t startVirtualAddress, uint32_t len, uint8_t *data)
{
  if ((startVirtualAddress + len) > EE_SIZE)
    return false;
  if (data == NULL)
    return false;
  HAL_FLASH_Unlock();

  for (uint32_t i = 0; i < len; i += 8)
  {
    uint64_t data64 = data[i];
    data64 += data[i + 1] * 0x100;
    data64 += data[i + 2] * 0x10000;
    data64 += data[i + 3] * 0x1000000;
    data64 += data[i + 4] * 0x100000000;
    data64 += data[i + 5] * 0x10000000000;
    data64 += data[i + 6] * 0x1000000000000;
    data64 += data[i + 7] * 0x100000000000000;
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, ((i + startVirtualAddress)) + EE_BASE_ADDR, data64) != HAL_OK)
    {
      HAL_FLASH_Lock();
      return false;
    }
  }

	HAL_FLASH_Lock();
	return true;
}

/*
 * Funzione che scrive dati in un buffer nella RAM
 *
 * @param StartVirtualAddress: l'indice base del buffer
 * @param len: numero di dati che si vogliono copiare nel buffer
 * @param data: puntatore all'array contenente i dati da copiare nel buffer
 *
 * */

bool ee_writeToRam(uint32_t startVirtualAddress, uint32_t len, uint8_t* data)
{
#if (EE_USED_RAM_BYTE > 0)
  if ((startVirtualAddress + len) > EE_USED_RAM_BYTE)
    return false;
  if (data == NULL)
    return false;
  memcpy(&ee_ram[startVirtualAddress], data, len);
  return true;
#else
  return false;
#endif
}

/*
 * Funzione che 1)formatta la zona della flash usata per l'emulazione della eeprom e 2)copia i dati dalla RAM nella flash(/eeprom)
 *
 * Nota: tale funzione va utilizzata dopo aver scritto nella RAM utilizzando la funzione ee_writeToRam
 * */

bool  ee_commit(void)
{
#if (EE_USED_RAM_BYTE > 0)
  if (ee_format(true) == false)
    return false;
  return ee_write(0, EE_USED_RAM_BYTE, ee_ram);
#else
  return false;
#endif
}
