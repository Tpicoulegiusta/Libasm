bits 64

;rdi = dest;
;rsi = src;
;rax = adresse de dest a retourner;



section .text
	global ft_strcpy
	ft_strcpy:
	mov rax, rdi ;on stock le debut de l'adresse de la chaine a retourner;

	.looping:
	mov r9b, [rsi] 		; On met l'octet de src dans r9b;
	mov [rdi], r9b 		; On l'ecrit dans dest (rdi);
	test r9b, r9b 		; On teste si l'octet vaut 0;
	je .return

	inc rsi
	inc rdi
	jmp .looping


	.return:
	ret