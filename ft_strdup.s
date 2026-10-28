;rdi = s;
;rax = valeur de retour comme d'hab enft;
;strdup l'adresse de la nouvelle chaine dupliquee a partir de S;


bits 64


extern ft_strlen
extern ft_strcpy
extern malloc


section .text
	global ft_strdup
	ft_strdup:
	push rdi 						; push rdi sur la pile pour sauvegarder S(rdi detient S);
		call ft_strlen wrt ..plt	; appelle de la fonction strlen;
	inc rax 						; on incremente rax qui detient la taille de S pour rajouter le \0;
	;On a la bonne taille ca y est  ;

	mov rdi, rax 					; malloc a besoin de la taille a allouer dans rdi;
		call malloc wrt ..plt	 	; On call malloc avec la taille de S dans rdi et il nous renvoie adresse allouee dans rax;
	;Rax a l'addresse				;
	pop rsi 						; On realigne la pile et on recupere rsi qui sert de deuxieme arg a cpy;
	test rax, rax 					; On regarde la valeur de Rax;
	jz .return 						; Si malloc echoue, on return NULL;

	; pop rsi 						; On recupere rsi qui sert de deuxieme argument a strcpy;
	mov rdi, rax 					; on met la dest dans rdi (le resultat de malloc);
		call ft_strcpy wrt ..plt	; On appelle la fonction strcpy;


	.return:
	ret