# read_GUID
C program which processes GUID from binary file.

###Usage:
`command [files...]`

The command accept 0 or more additional arguments.

If no argument, you need to enter the input file name as prompted.

If arguments are entered, they will be used as file names. The program will process each file respectively.

###Input File:
All input files will be treated as binary files.

###Note:
Program reads 16 bytes from input file each time, same as the length of a GUID.

GUID stored in binary file is grouped by bytes as below: 
4-2-2-[1X8]
