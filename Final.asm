include macros2.asm
include number.asm
.MODEL LARGE
.386
.STACK 200h

.DATA
@msg db "Ingrese un número:", '$'
contador dd ?
promedio dd ?
actual dd ?
suma dd ?
pivot dd ?
_Prueba_txt_LyC_Tema_2 db "Prueba.txt LyC Tema 2!" , '$', 24 dup (?)
_Ingrese_un_valor_entero_ db "Ingrese un valor entero: " , '$', 27 dup (?)
_0 dd 0.0
_2_5 dd 2.5
_0xA2B0 dd 0A2B0h
@aux7 dd ?
_9 dd 9.0
_1 dd 1.0
@aux18 dd ?
_0_342 dd 0.342
@aux22 dd ?
@aux26 dd ?
_2 dd 2.0
@aux35 dd ?
_4 dd 4.0
_0b110 dd 0110b
@aux dd ?
@max2 dd ?
@max1 dd ?
@aux58 dd ?
@aux59 dd ?
@aux63 dd ?
_La_suma_es_ db "La suma es: " , '$', 14 dup (?)
_0b10 dd 010b
_actual_es_mayor_que_2 db "actual es mayor que 2" , '$', 23 dup (?)
_0b111010 dd 0111010b
_no_es_mayor_que_2 db "no es mayor que 2" , '$', 19 dup (?)

.CODE

START:

MOV AX,@DATA
MOV DS, AX
MOV ES, AX

mov dx,OFFSET _Prueba_txt_LyC_Tema_2
mov ah,9
int 21h
newline 1

mov dx,OFFSET _Ingrese_un_valor_entero_
mov ah,9
int 21h
newline 1

DisplayString @msg 
int 21h 
newLine 1
GetFloat actual 

fld _0
fstp contador
fld _2.5
fld _0xA2B0
fadd
fstp @aux7
fld @aux7
fstp suma
fld _0
fstp pivot

etiqueta_11:
fld contador
fld _9
fxch
fcomp
fstsw ax
sahf
JA etiqueta_66

fld contador
fld _1
fadd
fstp @aux18
fld @aux18
fstp contador
fld contador
fld _0.342
fdiv
fstp @aux22
fld actual
fld contador
fmul
fstp @aux26
fld @aux26
fstp @max1
fld _2
fstp @aux
fld @aux
fld @max1
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_33

fld @aux
fstp @max1

etiqueta_33:
fld actual
fld pivot
fmul
fstp @aux35
fld @aux35
fstp @aux
fld @aux
fld @max1
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_40

fld @aux
fstp @max1

etiqueta_40:
fld _4
fstp @max2
fld actual
fstp @aux
fld @aux
fld @max2
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_47

fld @aux
fstp @max2

etiqueta_47:
fld _0b110
fstp @aux
fld @aux
fld @max2
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_52

fld @aux
fstp @max2

etiqueta_52:
fld @max2
fstp @aux
fld @aux
fld @max1
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_57

fld @aux
fstp @max1

etiqueta_57:
fld contador
fld @max1
fmul
fstp @aux58
fld @aux22
fld @aux58
fadd
fstp @aux59
fld @aux59
fstp actual
fld suma
fld actual
fadd
fstp @aux63
fld @aux63
fstp suma

etiqueta_65:
JMP etiqueta_11


etiqueta_66:
mov dx,OFFSET _La_suma_es_
mov ah,9
int 21h
newline 1

mov dx,OFFSET suma
mov ah,9
int 21h
newline 1

fld actual
fld _0b10
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_78

fld actual
fld _0
fxch
fcomp
fstsw ax
sahf
JE etiqueta_78

mov dx,OFFSET _actual_es_mayor_que_2
mov ah,9
int 21h
newline 1

JMP etiqueta_83


etiqueta_78:
fld actual
fld _0b111010
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_83

mov dx,OFFSET _no_es_mayor_que_2
mov ah,9
int 21h
newline 1


etiqueta_83:
MOV EAX, 4C00h
INT 21h

END
