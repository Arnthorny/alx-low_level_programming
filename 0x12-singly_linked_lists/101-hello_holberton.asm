
section .data
	message db "Hello, Holberton", 0 ; null-byte terminated string
	format db "%s", 10, 0 ; string containing "%s\n"

section .text
	default rel 	;nasm assembly directive.
			;tells nasm to use rip relative addressing
	extern printf ;printf symbol exists outside file
	global main; ;similar to exporting main function

main:
	push rbp ;Create a stack frame, re-aligning the stack to 16-byte alignment

	mov rdi, format ;rdi register stores arg0
	mov rsi, message ; rsi register stores arg1
	mov rax, 0 ; rax register stores return value, also syscall number

	call printf ;Call printf

	pop rbp	;Pop stack

	mov rax, 0 ;Exit code 0
	ret
