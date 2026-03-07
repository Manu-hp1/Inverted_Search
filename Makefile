OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
inv_sh.out: $(OBJ)
	gcc -o $@ $^  
clean:
	rm *.o