ASSUME CS:CODE
CODE SEGMENT
        START:
        MOV AX, 25H
        AND AX, 0FH
        MOV BX, AX
        MOV AX, 25H
        AND AX, 0F0H
        MOV CL, 03H
        ROR AL, CL
        MOV CX, 0AH
        MUL CX
        ADD AX, BX
        INT 21H
        HLT
    CODE ENDS
END START