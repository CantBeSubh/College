CODESEG SEGMENT
            ASSUME CS:CODESEG
    START:  
            MOV    AX, 1010H
            MOV    BX, 0005H
            MUL    AX,BX
            HLT
CODESEG ENDS
END START