	.arch msp430g2553
	.p2align 1,0		        ; set memory boundary of 2 bytes with padding of zeroes

	.text
	.align 2
	.global drawPix
	.extern drawPixel


drawPix:
	mov #10, r12;col
	mov #150, r13;row
	mov 0x0000, r14;
	call #drawPixel
 	pop r0
