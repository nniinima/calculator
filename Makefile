
NAME = calculator

OUT = calculator

all: $(OUT)

$(OUT):
	gcc -c -Wall -Wextra -Werror *.c -lm
	gcc -o $(NAME) -Wall -Wextra -Werror *.o -lm
clean:
	/bin/rm -f *.o
fclean:clean
	/bin/rm -f $(OUT)
re: fclean all
