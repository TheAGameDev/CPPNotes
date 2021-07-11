/*
 TODO: C printf format specifiers
 %c     character
 %d     decimal (integer) number (base 10)
 %e     exponential floating-point number
 %f     floating-point number
 %i     integer (base 10)
 %o     octal number (base 8)
 %s     a string of characters
 %u     unsigned decimal (integer) number
 %x     number in hexadecimal (base 16)
 %%     print a percent sign
 \%     print a percent sign

 TODO: Right justified printf statements
 printf("%3d", 0);          0
 printf("%3d", 123456789);  123456789
 printf("%3d", -10);        -10
 printf("%3d", -123456789); -123456789

 TODO: Left justified printf statements
 printf("%-3d", 0);             0
 printf("%-3d", 123456789);     123456789
 printf("%-3d", -10);           -10
 printf("%-3d", -123456789);    -123456789

 TODO: Zero fill printf statements
 printf("%03d", 0);             000
 printf("%03d", 1);             001
 printf("%03d", 123456789);     123456789
 printf("%03d", -10);           -10
 printf("%03d", -123456789);    -123456789

 TODO: Printf integer formatting
 At least five wide                         printf("'%5d'", 10);        '   10'
 At least five-wide, left-justified         printf("'%-5d'", 10);       '10   '
 At least five-wide, zero-filled            printf("'%05d'", 10);       '00010'
 At least five-wide, with a plus sign       printf("'%+5d'", 10);       '  +10'
 Five-wide, plus sign, left-justified       printf("'%-+5d'", 10);      '+10  '

 TODO: Formatting point numbers
 Print one position after the decimal                           printf("'%.1f'", 10.3456);              '10.3'
 Two positions after the decimal                                printf("'%.2f'", 10.3456);              '10.35'
 Eight-wide, two positions after the decimal                    printf("'%8.2f'", 10.3456);             '   10.35'
 Eight-wide, four positions after the decimal                   printf("'%8.4f'", 10.3456);             ' 10.3456'
 Eight-wide, two positions after the decimal, zero-filled       printf("'%08.2f'", 10.3456);            '00010.35'
 Eight-wide, two positions after the decimal, left-justified    printf("'%-8.2f'", 10.3456);            '10.35   '
 Printing a much larger number with that same format            printf("'%-8.2f'", 101234567.3456);     '101234567.35'

 TODO: Printf string formatting
 A simple string                    printf("'%s'", "Hello");        'Hello'
 A string with a minimum length     printf("'%10s'", "Hello");      '     Hello'
 Minimum length, left-justified     printf("'%-10s'", "Hello");     'Hello     '

 TODO: Printf special characters
 \a     audible alert
 \b     backspace
 \f     form feed
 \n     newline, or linefeed
 \r     carriage return
 \t     tab
 \v     vertical tab
 \\     backslash

 Insert a tab character in a string             printf("Hello\tworld");             Hello world
 Insert a newline character in a string         printf("Hello\nworld");             Hello
                                                                                    world
 Typical use of the newline character           printf("Hello world\n");            Hello world
 A DOS/Windows path with backslash characters   printf("C:\\Windows\\System32\\");  C:\Windows\System32\
 ---------------ANSI_COLOR_CODES---------------
 TODO: REGULAR COLORS
 \x1b[0;30m	    Black
 \x1b[0;31m	    Red
 \x1b[0;32m	    Green
 \x1b[0;33m	    Yellow
 \x1b[0;34m	    Blue
 \x1b[0;35m	    Purple
 \x1b[0;36m	    Cyan
 \x1b[0;37m	    White
 TODO: BOLD
 \x1b[1;30m	    Black
 \x1b[1;31m 	   Red
 \x1b[1;32m	    Green
 \x1b[1;33m	    Yellow
 \x1b[1;34m	    Blue
 \x1b[1;35m	    Purple
 \x1b[1;36m	    Cyan
 \x1b[1;37m  	  White
 TODO: UNDERLINE
 \x1b[4;30m	    Black
 \x1b[4;31m	    Red
 \x1b[4;32m	    Green
 \x1b[4;33m	    Yellow
 \x1b[4;34m	    Blue
 \x1b[4;35m	    Purple
 \x1b[4;36m	    Cyan
 \x1b[4;37m	    White
 TODO: BACKGROUND
 \x1b[40m	      Black
 \x1b[41m	      Red
 \x1b[42m	      Green
 \x1b[43m	      Yellow
 \x1b[44m	      Blue
 \x1b[45m	      Purple
 \x1b[46m	      Cyan
 \x1b[47m	      White
 TODO: HIGH INTENSITY
 \x1b[0;90m	    Black
 \x1b[0;91m	    Red
 \x1b[0;92m	    Green
 \x1b[0;93m	    Yellow
 \x1b[0;94m	    Blue
 \x1b[0;95m	    Purple
 \x1b[0;96m	    Cyan
 \x1b[0;97m	    White
 TODO: BOLD HIGH INTENSITY
 \x1b[1;90m	    Black
 \x1b[1;91m	    Red
 \x1b[1;92m	    Green
 \x1b[1;93m	    Yellow
 \x1b[1;94m	    Blue
 \x1b[1;95m 	   Purple
 \x1b[1;96m	    Cyan
 \x1b[1;97m	    White
 TODO: HIGH INTENSITY BACKGROUNDS
 \x1b[0;100m	   Black
 \x1b[0;101m	   Red
 \x1b[0;102m	   Green
 \x1b[0;103m	   Yellow
 \x1b[0;104m 	  Blue
 \x1b[0;105m	   Purple
 \x1b[0;106m	   Cyan
 \x1b[0;107m	   White
 TODO: RESET
 \x1b[0m	       Reset
 */