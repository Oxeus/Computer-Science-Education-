	.file	"asm.c"
	.globl	charArray
	.data
	.align 8
	.type	charArray, @object
	.size	charArray, 12
charArray:
	.byte	10
	.byte	11
	.byte	12
	.byte	13
	.byte	14
	.byte	15
	.byte	26
	.byte	27
	.byte	28
	.byte	29
	.byte	30
	.byte	31
	.globl	intArray
	.align 32
	.type	intArray, @object
	.size	intArray, 40
intArray:
	.long	10
	.long	11
	.long	12
	.long	13
	.long	14
	.long	15
	.long	16
	.long	17
	.long	18
	.long	19
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movl	%edi, -28(%rbp)
	movq	%rsi, -40(%rbp)
	movl	$305419896, -12(%rbp)
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -24(%rbp)
#APP
# 13 "asm.c" 1
			mov		$0x89ABCDEF, %eax			
		mov		$0xFF, %bl					
		movsx	%bl, %eax					
		movzx	%bl, %eax					
		mov	 	$0x12, %al	
		mov		$0x34, %ah
		mov		$0xBBBBBBBB, %ebx			
		mov		$0xAAAAAAAA, %eax			
		xchg	%ebx, %eax				
		mov		-12(%rbp), %eax		
		add		$4, %eax					
		mov		%eax, -12(%rbp)		
		mov		$3, %ecx					
		lea		intArray(%rip), %ebx			
		mov		(%ebx), %eax				
		mov		(%ebx, %ecx, 4), %eax	
		mov		$0, %eax					
		lea		charArray(%rip), %ebx			
		mov		(%ebx), %al				
		mov		(%ebx, %ecx, 1), %al		
		cmp		$3, -12(%rbp)			
		jg		gt							
		nop									
gt:	nop									
		fldl	-24(%rbp)					
		fld		%st						
		faddp								
		fstpl	-24(%rbp)					

# 0 "" 2
#NO_APP
	movl	$0, %eax
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1076887552
	.ident	"GCC: (GNU) 5.2.0"
	.section	.note.GNU-stack,"",@progbits
