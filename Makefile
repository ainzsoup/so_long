all:
	cc -I /usr/local/include main.c get_next_line.c get_res.c  -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

clean:
	rm a.out

re:	all
	./a.out
	