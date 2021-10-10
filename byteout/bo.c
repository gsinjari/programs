// bo is ByteOut v1.0
// By Govand Sinjari @ 2014-08-17 
// This command will output  number of bytes from a file in specified format
// Format: x for hex; o for oct; d for decimal ; c for char; p for pointer; s for string, this will output number of lines. Actually you can use all printf format specifiers, so don't exploit it ;) 
// author			: @g0vandS
// license           : MIT



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main(int argc, char* argv[])
{

//printf("***\tByteOut\t\t\t\t***\n***\tBy Govand Sinjari @ 2014-08-17\t***\n");

// Verify that command got exactly 3 args
if (argc != 4)
	{
	printf("***\tByteOut   v1.0\t\t\t***\n***\tBy Govand Sinjari @ 2014-08-17\t***\n");
	printf("This command will output number of bytes from a file in specified format\n");
	printf("Format: x for hex; o for oct; d for decimal ; c for char; p for pointer; s for string, this will output number of lines. Actually you can use all printf format specifiers, so don't exploit it ;)\n\n");

	printf("Error!!, command need 3 args, please use %s bytes format filename, i.e\t %s 10 x file.txt\n", argv[0], argv[0]);
	return 1;
	}
/*
// Print all provided args
for (int x=0; x < argc; x++)
	{	
        	printf("Arg [%d] =  %s\n", x,argv[x]);
   	}
*/

// Read file and verify it does exist
FILE *fn;
if ((fn = fopen (argv[3], "r")) == NULL) {
	printf ("Can't open the file: %s\n", argv[3]);
	return 1;
}

char arg[20];
strcpy (arg, "%");
strcat (arg, argv[2]);
strcat (arg, " ");

//arg[0] = '%';
//arg[1] = argv[2][0];
//arg[2] = ' ';
//arg[3] = '\0';

if (strcmp(argv[2], "s")) {

	for (int c=0 ; c < atoi(argv[1]); c++)
	{
		printf(arg,getc(fn));
	}
} else 

{
	char str[255];
	for (int c=0 ; (c < atoi(argv[1])) && !feof(fn); c++)
        {
		fgets (str, 255, fn);
		printf("%s", str);
        }

}

printf("\n");


//Close the opened file
fclose(fn);
    
return 0;
}
