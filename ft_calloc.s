;nmemb = rdi;
;size = rsi;
;valeur de retour = rax;

extern malloc


bits 64

extern malloc
extern __errno_location
ENOMEM equ 12

section .text
	global ft_calloc
	ft_calloc:
	mov rax, rdi 				; on met rdi dans rax;
	mul rsi 					; On multiplie rax et rsi et on le met dans rax, ici on ne peut pas utiliser deux registre 
	 							; de memoire pour le faire donc on utilise rax, mul utilise rax en premier facteur;
	jc .error	 				; jump if overflow(carry flag), le produit depasse 64bits;
							

	push rax 					; On securise la taille totale sur la pile;
	mov rdi, rax 				; On met rax dans rdi pour appeler malloc, malloc ayant besoin de la taille;
		call malloc wrt ..plt	; On call malloc;
	pop rcx 					; On recupere la taille sauvegardee dans la pile;
	test rax, rax 				; On regarde la valeur de Rax;
	jz .return 					; Si malloc echoue, on return NULL;


	mov r8, rax 				; On stock dans r8 l'addresse de depart;
	test rcx, rcx 				; On regarde la taille, si 0, rien a mettre;
	jz .return


	.zero:
	mov byte [r8], 0 			; On ecrit l'octet 0 a l'adresse dans r8
	inc r8 						; On avance dans r8;
	dec rcx 					; On decrement rcx;
	jnz .zero 					; Tant que rcx a des octets on continue;

	.return:
	ret 						; Si tous se passe bien on return noramal;


	.error:
	sub rsp, 8 							; On aligne la pile avant le call;
	call __errno_location wrt ..plt 	; Errno etant propre a chaque thread on demande la location, elle sera stocke dans rax;
	mov dword [rax], ENOMEM				; On copie 4octet (un int(dword)) a l'adresse contenue par rax, c'est a dire ENOMEM(12);
	add rsp, 8 							; On remet la pile apres le call;
	xor rax, rax 						; On met rax a 0 pour return la bonne valeur;
	ret 								; Ici on return lorsque ca se passe mal;

