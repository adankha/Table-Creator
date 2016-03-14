# DIRECTIONS

To use the program correctly, follow the instructions below:

Step 1: 
Download t1RNG.c FROM HERE and put it in the directory you're working in.

Step 2:
Download rnames.txt FROM HERE and put it in the directory you're working in.

Step 3:
gcc t1RNG.c
./a.out X Y rnames.txt > tnew
X and Y are the number of rows and columns respectively. For simplicity, the program will work for an X range from 1-100 inclusive and Y range from 1 - 20.

Step 4:
Open the file containing the table, in our case:
vim tnew
IMPORTANT:
If you notice name^M: in the file when using vim, you can either manually delete all the ^M's, or type,
:%s/\r//g
in the command line when you have the file open. It will remove all ^M instances. (This is important so that you can use the table and it will work as intended for our program). If this command doesn't work, or you're using something other than vim, just google how to remove the ^M.

Once you've done this, you are able to run the program using your new table.
