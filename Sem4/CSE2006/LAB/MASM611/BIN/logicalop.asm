ASSUME CS:CODE
CODE SEGMENT
        START:
        MOV AH, 10H
        MOV BL, 0FH
        MOV CL, 04H
        ROR AH, CL
        AND AH, BL
        AND AH, 25H
        MOV AL, 10H
        AND AL, BL
        ADD AL, 25H
        HLT
    CODE ENDS
END START