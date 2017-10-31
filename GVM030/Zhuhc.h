#ifndef __ZHUHC_H
#define __ZHUHC_H

#include "gvm32f030.h"

#define SEND_PORT      UART0

void CX_SendImage(void *imgaddr, uint32_t imgsize);
void CX_SendCCD(void *ccdaddr, uint32_t ccdsize);
void CX_SendWare(void *wareaddr, uint32_t waresize);

#endif
