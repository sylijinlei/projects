#ifndef _NAND_H
#define _NAND_H

#include "types.h"

void nand_init(void);
void nand_read_id(u8 *buff)  ;

int nand_read(unsigned int ddr_start, unsigned int nand_start,  unsigned int len);
int nand_write(unsigned char * buf, unsigned int nand_start, unsigned int len);

int nand_erase_block(unsigned long addr);
int copy2ddr(unsigned int ddr_start,unsigned int nand_start,  unsigned int len);

#endif

