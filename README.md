# Pushswap
Test
Thing working, i gotta organize the num validation, not repeating number, etc

Have a look to create free, doesnt link to exiting() for some reason

doesnt link with this one neither 
throws this error continiously
home/havr/Desktop/Push_swap/Push/main.c:31: undefined reference to `val_split'

library seems to be fine, as make file is

Organizing idea
a**rgv -> send to validate as a doublepointer, cause Split will returna double pointer as well.
 I CAME UP WITH THE IDEA OF SPLITTING RIGHT away every argument perhps with strhcr before hand where a worng caracter or . or , can be evaluated

    loop not with a reverse counter, as if its called recursevely,  counting separators would be needed

    every argv, if not split

MEmory leaks due to wrong setting probably  while building the list. at least first elemnt doesnt link

All handlers working correctly
I added a printing function, also working ok
when calling print fun, after or before, i wshould FREE.

NEED TO MAKE AN EXITING_FUNCTION TO FREE PROPERLY,

I guess i can pass ENDS and allocate and free if needed.
FOR MAKE LIST, I GOTTA LOOP ARGV
    I HAVE TO VALIDATE IT HAS NO SPACES IF YES SPLIT THEM., make a TEMP ** to free
        LOOPING THAT SPLIT
            AFTER VALIDATING THEM, MAKE A NEW ELEMENT AND FREE TMP = NULL.
            if it fails, exiting



The ATOI had to be changed to long long, to old a number that size in case of, to be free later

I dont know if i should free the argv once i aplit it :-( 

i DEFEINETELY NEED A MAKE FILE AND TO INTEGRATE DE LIBFT

)