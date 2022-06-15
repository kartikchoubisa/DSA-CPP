.model tiny
.486
.data
    max1 db 21 ; max no of chars allowed (including return)
    act1 db ? ; actual count of keys typed by user
    inp1 db 22 dup('$') ; reserve 20 + 2 locations
    ; 20 letters in username, 1 return char, 1 $ char
    disnl db 0DH, 0AH, '$'

.code
.startup
    lea DX, max1
    mov AH, 0Ah ; displays string
    int 21h
    lea dx, disnl
    mov ah, 09h
    int 21h
    lea dx, inp1
    mov ah, 09h
    int 21h
.exit
end

