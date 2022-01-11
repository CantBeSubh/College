CODESEG SEGMENT
            ASSUME CS:CODESEG
    START:  
            MOV    AX, 1010H
            MOV    BX, 0005H
            DIV    AX,BX
            HLT
CODESEG ENDS
END START
