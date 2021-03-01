Ivan Stus
cssc1943
CS530, Spring 2020
Assignment #1, hexDump/binDump
README.txt

Files in Assignment #1:
dbx.c (source file)
include.h (header/include file)
Makefile
README.txt

Compile Instructions:
make
makeclean

Operating Instructions:
In the command line type "gcc dbx.c -o dbx"
after, type "dbx (-b for binary) (name of file to be tested)

Design Decisions:
I decided to add a check for if the program was to convert the bytes to hex or binary. Once the check passed, the appropriate method would be called. 
I also decided to do the binary conversion in a separate method to keep the code cleaner.

Extra Features:
Command line is prompted again if the correct input in the command line is not inputted.

Bugs:
Not really a bug, but more like human error, I didn't quite have time to fix this but, when converting to binary or hex the line continues until it reaches the end 
of the line. This means that there is extra left over code being written to output after the program runs. I should've also added a check near the beginning of my
while loops that checked that the EOF has been reached. This would stop my loops until the file is done.

Lessons Learned:
This was a very hard program for me considering this is basically my first time using C. I learned how to open and read files in C and convert bytes to their 
hexadecimal/binary equivalents. Another lesson is to start as early as possible on these programs and stop procrastinating, hopefully that will be fixed for
the next one.

