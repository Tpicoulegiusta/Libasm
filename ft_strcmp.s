bits 64
;s1 = rdi;
;s2 = rsi;
;return = rax;


section .text
	global ft_strcmp
	ft_strcmp:
	xor r9, r9


	.looping:
	mov al, [rdi + r9]
	mov dl, [rsi + r9]

	cmp al, dl
	jne .return
	
	cmp byte [rdi + r9], 0
	je .return
	
	inc r9
	jmp .looping


	.return:
	movzx rax, al
	movzx rdx, dl
	sub rax, rdx
	ret