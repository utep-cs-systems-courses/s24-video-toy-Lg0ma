	.arch msp430g2553
	.p2align 1,0		        ; set memory boundary of 2 bytes with padding of zeroes

	.text
	.align 2
	.global drawLine
	.extern drawPixel

drawLine:
	sub #6, r1
    mov.b r12, 0(r1) ; col
    mov.b r13, 1(r1) ;row
    mov.b r14, 2(r1) ;size
    mov.b r15, 3(r1) ;color
    mov.b #0, 4(r1) ; i=0
Top:
    cmp 2(r1), 4(r1); i-size
    jc Out
    add #1, 0(r1)
    mov.b 0(r1), r12
    sub #1, 1(r1)
    mov.b 1(r1), r13
    mov.b 3(r1), r14
    call #drawPixel
    add #1, 4(r1)
    goto Top
Out:
    add #6, r1
    pop r0