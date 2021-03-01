###########################################################
# Ivan Stus 
# cssc1943
# CS530, Spring 2020
# Assignment #1, hexDump/binDump
# Makefile
###########################################################
dbx: dbx.c
	gcc -o dbx dbx.c
clean:
	rm dbx
#######################[ EOF: Makefile ]###################