flex Lexico.l
gcc lex.yy.c -o compilador
./compilador prueba.txt
rm lex.yy.c
rm compilador
