*This project has been created as part of the 42 curriculum by vmourey.*

#PRINTF

##DESCRIPTION :
This project has for goal to recreate most of the basic capabilities from the printf function, found in the <stdio.h> library. 
To be more precise, the ft_printf function is able to print to the standard stream :
- a single character using %c.
- a % using %%.
- a string by default or by using %s.
- an integer, whether signed or unsigned, using %d (or %i) or %u, respectively.
- the hexadecimal conversion of a unsigned integer, using %x for lowercase letters or %X for uppercase letters. 
- or a pointer, using %p.
while returning the number of characters printed.
Finally, it’s also able to combine those options in one line through the use of multiple % in the first string, paired with the right arguments.

##INSTRUCTIONS :
To obtain the library containing the ft_printf fonction, it is enough to execute the “make all” or “make libftprintf.a” command in the terminal in the folder containing the makefile. Once the library is obtained, it can be compiled alongside a .c file to allow the use of the function in it.
The temporary files thus created can be removed using either “make clean” or “make fclean”, depending on whether you also want to erase the library.
Finally, the “make re” command can be used to remove the library and the leftovers temporary files before recreating them.

##RESOURCES:
After the majority of the code had already been produced, I consulted the following reference to make sure I didn’t make a mistake.
- https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf

##ALGORITHM:
To create this function, I decided to go through the first argument, a string, one character at a time, printing said character using write, with the exception of the ‘%’ characters.
When finding one of those, it is required to check the following character in order to determine the nature what will need to be printed and thus the helper function(s) to use. Afterwards, we apply the needed transformation to the corresponding argument (the first % is paired with the second argument, the second % with the third argument, etc.., unless we have a %%, in which case no argument are used).
For %s, %c and %%, we only have to use to use a write to print the needed characters.
For %u, %i and %d, we use an itoa function turning the int argument into a string we can then print the same way as for %s.
For %x and %X, a function convert the integer from a base 10 to a base 16 number, the result being a string we can then print as we did previously.
Finally, for %p, the pointer is converted into an unsigned long then a string, before being displayed with the two characters “Ox” in front.
Meanwhile, in order to return the right integer corresponding to the number of printed characters, we count the length of the first argument, to which we add the number of characters added by any of the helper function minus 2, for the two characters indicating that an helper function is to be used (ex : %s).

