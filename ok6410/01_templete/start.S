  
.globl _start
_start:

/* ç¡¬ä»¶ç›¸å…³çš„è®¾ç½® */
    /* Peri port setup */
    ldr r0, =0x70000000
    orr r0, r0, #0x13
    mcr p15,0,r0,c15,c2,4       @ 256M(0x70000000-0x7fffffff)
    
/* å…³çœ‹é—¨ç‹— */
/* å¾€WTCON(0x7E004000)å†™0 */
	
	ldr r0, =0x7E004000
	mov r1, #0
	str r1, [r0]
	
	/* è®¾ç½®æ ˆ */
	ldr sp, =8*1024

	/* è®¾ç½®æ—¶é’Ÿ */
	bl clock_init
	bl sdram_init


/* æŠŠBSSæ®µå¯¹åº”çš„å†…å­˜æ¸…é›¶ */
	adr r1, _start   /* »ñµÃ_startÖ¸Áîµ±Ç°ËùÔÚµÄµØÖ· : 0*/
	ldr r0, =_start  /* _startµÄÁ´½ÓµØÖ· 0x50000000 */
	
	ldr r2, =bss_start      /* bss¶ÎµÄÆðÊ¼Á´½ÓµØÖ· */
	sub r2, r2, r0
	cmp r0,r1
	beq clean_bss
	
bl copy2ddr
	cmp r0, #0
	bne halt
	
clean_bss:
	ldr r0, =bss_start
	ldr r1, =bss_end
	mov r3, #0
	cmp r0, r1
	beq on_ddr
clean_loop:
	str r3, [r0], #4
	cmp r0, r1	
	bne clean_loop	


on_ddr:
	ldr pc, =main
halt:
	b halt	
