flex Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c -o compilador
./compilador prueba.txt
rm lex.yy.c
rm y.output
rm compilador
