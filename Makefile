DIRECTORY = library/

all: 
	cd $(DIRECTORY); make
clean:
	cd $(DIRECTORY); make clean
fclean:
	make -C $(DIRECTORY) fclean
re:
	make -C $(DIRECTORY) re
