flex Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c -o compilador
./compilador prueba2.txt
rm lex.yy.c
rm y.output
rm compilador
rm y.tab.c
rm y.tab.h