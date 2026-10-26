bits 64

;rdi = dest;
;rsi = src;
;rax = adresse de dest a retourner;



section .text
	global ft_strcpy
	ft_strcpy:
	xor r8, r8 ;on met le compteur a 0;
	mov rax, rdi ;on stock le debut de l'adresse de la chaine a retourner;

	.looping:
	mov [rdi], r9b 
	mov r9b, [rsi]
	cmp byte [rsi], 0 ;compare l'octet en memoire a l'adresse rsi + r8;
	je .return

	inc rsi
	inc rdi
	jmp .looping


	.return:
	ret