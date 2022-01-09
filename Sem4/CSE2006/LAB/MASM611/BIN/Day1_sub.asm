code segment
assume cs:code
start:
mov al,04h
mov bl,05h
sub al,bl
hlt
code ends
end