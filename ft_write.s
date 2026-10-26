


bits 64

extern __errno_location


section .text
	global ft_write
	ft_write:
	mov rax, 1
	syscall

	test rax, rax 	; ne fait rien sauf regarder la veleur de rax;
	jns .return   	; jump if not sign(saute si le chiffre n'est pas -);

	neg rax 				; on obtient -9 dans rax donc on la transforme en 9 car errno ne prend pas les negatifs;
	push rax 				; je met rax sur la pile pour ne pas le perdre, car il va etre modifie plus tard;
	call __errno_location  wrt ..plt  ; fonction qui retourne dans rax l'adresse memoire ou se trouve errno;
	pop rdi 				; je recupere 9 depuis la pile;
	mov [rax], edi			; rax contient une adresse dans laquelle on met 9;
							; errno est donc egal a 9;
	mov rax, -1				; raz = -1, la valeur de retour de la fonction en C;


	.return:
	ret