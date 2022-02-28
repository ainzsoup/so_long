all:
	cc -I /usr/local/include so_long.c get_next_line.c get_res.c check_map.c get_map.c draw_map.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

clean:
	rm a.out

re:	all
	./a.out
	