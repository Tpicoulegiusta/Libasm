bits 64

;constantes
; FD_OUT: equ 1
; SYS_EXIT: equ 60

; section .data


section .text
	global ft_strlen
	ft_strlen:
	xor rax, rax ;operation binaire qui met 1 si les deux bits sont differents
	
	.looping:
	cmp byte [rdi + rax], 0 ;compare l'octet en memoire a l'adresse rdi + rax
	je .return
	inc rax
	jmp .looping

	.return:
	ret

	; quitter le programme
	; .exit_program:
	; mov rax, SYS_EXIT
	; mov rdi, 0
	; syscall
