
#include "stdbool.h"
#include "string.h"

#ifndef INC_EEPROM_EMUL_H_
#define INC_EEPROM_EMUL_H_


#include <stdbool.h>
#include "main.h"


bool      ee_init(void);
bool      ee_format(bool keepRamData);
bool      ee_read(uint32_t startVirtualAddress, uint32_t len, uint8_t* data);
bool      ee_write(uint32_t startVirtualAddress, uint32_t len, uint8_t* data);
bool      ee_writeToRam(uint32_t startVirtualAddress, uint32_t len, uint8_t* data); //  only use when _EE_USE_RAM_BYTE is enabled
bool      ee_commit(void);  //  only use when _EE_USE_RAM_BYTE is enabled
uint32_t  ee_maxVirtualAddress(void);


#endif /* INC_EEPROM_EMUL_H_ */
