/*
 * mycerts.h
 *
 *  Created on: 19 gen 2021
 *      Author: cocco
 */

#ifndef INC_MYCERTS_H_
#define INC_MYCERTS_H_

#include "macro_def.h"

/* Certificati utilizzati per validare la connessione al server (Modena e Mosquitto) */
#if defined (SERVER_MODENA)
//Modena
#define certificate															   \
		"-----BEGIN CERTIFICATE-----\r\n"									   \
		"MIIEEzCCAvugAwIBAgIJAN0/f83JD+j9MA0GCSqGSIb3DQEBCwUAMIGfMQswCQYD\r\n" \
		"VQQGEwJJVDELMAkGA1UECAwCTU8xDzANBgNVBAcMBk1vZGVuYTEZMBcGA1UECgwQ\r\n" \
		"RGF0YVJpdmVyIFMuci5sLjEWMBQGA1UECwwNSVQgRGVwYXJ0bWVudDEaMBgGA1UE\r\n" \
		"AwwRbXF0dC5kYXRhcml2ZXIuaXQxIzAhBgkqhkiG9w0BCQEWFGhvc3RpbmdAZGF0\r\n" \
		"YXJpdmVyLml0MB4XDTIwMTAwODE1NDkxOVoXDTIxMTAwODE1NDkxOVowgZ8xCzAJ\r\n" \
		"BgNVBAYTAklUMQswCQYDVQQIDAJNTzEPMA0GA1UEBwwGTW9kZW5hMRkwFwYDVQQK\r\n" \
		"DBBEYXRhUml2ZXIgUy5yLmwuMRYwFAYDVQQLDA1JVCBEZXBhcnRtZW50MRowGAYD\r\n" \
		"VQQDDBFtcXR0LmRhdGFyaXZlci5pdDEjMCEGCSqGSIb3DQEJARYUaG9zdGluZ0Bk\r\n" \
		"YXRhcml2ZXIuaXQwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDHvBcn\r\n" \
		"zQmkQTbvIpw2zcePhA/+X5hG/hXONlpj3+7z/37hI8Q8pmPCoyqno2+L1BNWERlY\r\n" \
		"VDUlcL+OwPaHrYRSbSmeRXGfeRp6qOa+wWKE3LtMCZN1D6z2OY3+smZ9Ob60A8/s\r\n" \
		"KxdTigg88sWi48iTcInTSuEy2Ixh1zsC0TFD2Me/Vxyk3EsvDROiYHwf5K1Ur6SB\r\n" \
		"jbj3Olmm7mXvrynjYfX+uzKELrkbjDpLfot7UGAEv8sf4P1tHz1WP0GZUlbw2gIC\r\n" \
		"ILHR+Bdazku8GTuZNLUopRqWDDQHUTqB3j2ORO/VeGh4RdzvQxJ3bYpaa+3lOMMA\r\n" \
		"isVd3xv5lePerm0PAgMBAAGjUDBOMB0GA1UdDgQWBBTz9ngRUjN8NyWmeWYQNO1l\r\n" \
		"HNpd9zAfBgNVHSMEGDAWgBTz9ngRUjN8NyWmeWYQNO1lHNpd9zAMBgNVHRMEBTAD\r\n" \
		"AQH/MA0GCSqGSIb3DQEBCwUAA4IBAQCiDc6HRzkVj+zcdz71nDDmcOthjDW3VPfg\r\n" \
		"TbMS3y9F2TZ/+TbmqARUSWoWEVOFztNpZzn60Gb9WVZzsQicAk09+ADiYNVZCIlu\r\n" \
		"/ASP1z+B3yBFK4B8HazkXA6QQw9UW5/9aWi8XQewDg2yB0GIW44Q/XIxlZVJrTLu\r\n" \
		"J/Xjsdzx7UTNZ48wRqNwzmxnxenJCrWVZVFKPqqxBCfwJlD6rn77zN9CoCGPpNSX\r\n" \
		"nPm+8SrAXL0TSelNM7VzypOvNVCQY5tjdeToaYStjgmhbB2Nu5CnFEk2bM5l716p\r\n" \
		"VoHJzqoz+nFE662NpA+Lw9Q8IJtw/MkgqlNbtWMrA41StfvP6FXc\r\n" 			   \
		"-----END CERTIFICATE-----\r\n"
#else
//Mosquitto
#define certificate															   \
		"-----BEGIN CERTIFICATE-----\r\n"									   \
		"MIIEAzCCAuugAwIBAgIUBY1hlCGvdj4NhBXkZ/uLUZNILAwwDQYJKoZIhvcNAQEL\r\n" \
		"BQAwgZAxCzAJBgNVBAYTAkdCMRcwFQYDVQQIDA5Vbml0ZWQgS2luZ2RvbTEOMAwG\r\n" \
		"A1UEBwwFRGVyYnkxEjAQBgNVBAoMCU1vc3F1aXR0bzELMAkGA1UECwwCQ0ExFjAU\r\n" \
		"BgNVBAMMDW1vc3F1aXR0by5vcmcxHzAdBgkqhkiG9w0BCQEWEHJvZ2VyQGF0Y2hv\r\n" \
		"by5vcmcwHhcNMjAwNjA5MTEwNjM5WhcNMzAwNjA3MTEwNjM5WjCBkDELMAkGA1UE\r\n" \
		"BhMCR0IxFzAVBgNVBAgMDlVuaXRlZCBLaW5nZG9tMQ4wDAYDVQQHDAVEZXJieTES\r\n" \
		"MBAGA1UECgwJTW9zcXVpdHRvMQswCQYDVQQLDAJDQTEWMBQGA1UEAwwNbW9zcXVp\r\n" \
		"dHRvLm9yZzEfMB0GCSqGSIb3DQEJARYQcm9nZXJAYXRjaG9vLm9yZzCCASIwDQYJ\r\n" \
		"KoZIhvcNAQEBBQADggEPADCCAQoCggEBAME0HKmIzfTOwkKLT3THHe+ObdizamPg\r\n" \
		"UZmD64Tf3zJdNeYGYn4CEXbyP6fy3tWc8S2boW6dzrH8SdFf9uo320GJA9B7U1FW\r\n" \
		"Te3xda/Lm3JFfaHjkWw7jBwcauQZjpGINHapHRlpiCZsquAthOgxW9SgDgYlGzEA\r\n" \
		"s06pkEFiMw+qDfLo/sxFKB6vQlFekMeCymjLCbNwPJyqyhFmPWwio/PDMruBTzPH\r\n" \
		"3cioBnrJWKXc3OjXdLGFJOfj7pP0j/dr2LH72eSvv3PQQFl90CZPFhrCUcRHSSxo\r\n" \
		"E6yjGOdnz7f6PveLIB574kQORwt8ePn0yidrTC1ictikED3nHYhMUOUCAwEAAaNT\r\n" \
		"MFEwHQYDVR0OBBYEFPVV6xBUFPiGKDyo5V3+Hbh4N9YSMB8GA1UdIwQYMBaAFPVV\r\n" \
		"6xBUFPiGKDyo5V3+Hbh4N9YSMA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEL\r\n" \
		"BQADggEBAGa9kS21N70ThM6/Hj9D7mbVxKLBjVWe2TPsGfbl3rEDfZ+OKRZ2j6AC\r\n" \
		"6r7jb4TZO3dzF2p6dgbrlU71Y/4K0TdzIjRj3cQ3KSm41JvUQ0hZ/c04iGDg/xWf\r\n" \
		"+pp58nfPAYwuerruPNWmlStWAXf0UTqRtg4hQDWBuUFDJTuWuuBvEXudz74eh/wK\r\n" \
		"sMwfu1HFvjy5Z0iMDU8PUDepjVolOCue9ashlS4EB5IECdSR2TItnAIiIwimx839\r\n" \
		"LdUdRudafMu5T5Xma182OC0/u/xRlEm+tvKGGmfFcN0piqVl8OrSPBgIlb+1IKJE\r\n" \
		"m/XriWr/Cq4h/JfB7NTsezVslgkBaoU=\r\n" 								   \
		"-----END CERTIFICATE-----\r\n"
#endif


#endif /* INC_MYCERTS_H_ */
