	NAME = libasm.a

	CC = gcc
	NASM = nasm

	CFLAGS = -Wall -Wextra -Werror -g
	NASMFLAGS = -f elf64 -g -F dwarf

	ASM_SRCS = ft_strlen.s \
			ft_strdup.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_write.s \
			ft_read.s \
			ft_calloc.s

	OBJS = $(ASM_SRCS:.s=.o)

	MAINS = main_ft_strlen \
			main_ft_strdup \
			main_ft_strcmp \
			main_ft_strcpy \
			main_ft_write \
			main_ft_read \
			main_ft_calloc

all: $(NAME) $(MAINS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

$(MAINS): %: %.c $(NAME)
	$(CC) $(CFLAGS) $< -L -lasm -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(MAINS)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re