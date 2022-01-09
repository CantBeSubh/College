code segment
assume cs:code
start:
mov al,04h
mov bl,05h
add al,bl
hlt
code ends
end