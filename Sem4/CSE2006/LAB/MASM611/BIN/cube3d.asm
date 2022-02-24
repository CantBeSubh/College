MOV SI, 600
MOV CL, [SI]

;code to make all elements in an array into cubes
INC SI
L1:
MOV AL, [SI]
MUL AL
MUL AL
MOV [SI],AL

INC SI
LOOP L1

;Average of array

MOV SI, 500
MOV DI, 600 
MOV AX, 0000
MOV CL, [SI] 
MOV BL, CL
INC SI
ADD AL, [SI] 
ADC AH
INC SI
DEC CL
JNZ 40E 
DIV BL 
MOV [DI]
HLT