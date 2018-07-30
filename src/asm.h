
#define PROC_V          "/proc/version"
//#define BOOT_PATH       "/boot/System.map-"
#define KALLSYMS        "/proc/kallsyms"

#define MAX_LEN         (256)
#define SYSCALL_MAX     (310)


#define SPRING_BOARD   \
     __asm__ __volatile__ (\
        "push $0\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $1\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $2\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $3\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $4\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $5\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $6\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $7\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $8\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $9\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $10\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $11\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $12\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $13\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $14\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $15\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $16\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $17\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $18\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $19\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $20\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $21\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $22\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $23\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $24\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $25\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $26\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $27\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $29\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $29\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $30\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $31\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $32\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $33\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $34\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $35\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $36\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $37\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $38\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $39\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $40\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $41\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $42\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $43\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $44\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $45\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $46\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $47\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $48\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $49\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $50\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $51\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $52\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $53\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $54\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $55\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $56\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $57\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $58\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $59\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $60\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $61\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $62\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $63\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $64\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $65\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $66\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $67\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $68\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $69\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $70\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $71\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $72\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $73\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $74\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $75\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $76\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $77\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $78\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $79\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $80\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $81\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $82\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $83\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $84\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $85\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $86\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $87\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $88\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $89\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $90\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $91\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $92\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $93\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $94\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $95\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $96\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $97\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $98\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $99\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $100\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $101\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $102\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $103\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $104\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $105\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $106\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $107\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $108\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $109\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $110\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $111\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $112\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $113\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $114\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $115\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $116\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $117\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $118\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $119\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $120\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $121\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $122\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $123\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $124\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $125\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $126\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $127\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $128\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $129\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $130\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $131\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $132\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $133\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $134\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $135\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $136\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $137\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $138\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $139\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $140\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $141\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $142\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $143\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $144\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $145\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $146\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $147\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $148\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $149\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $150\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $151\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $152\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $153\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $154\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $155\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $156\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $157\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $158\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $159\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $160\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $161\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $162\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $163\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $164\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $165\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $166\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $167\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $168\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $169\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $170\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $171\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $172\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $173\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $174\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $175\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $176\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $177\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $178\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $179\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $180\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $181\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $182\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $183\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $184\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $185\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $186\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $187\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $188\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $189\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $190\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $191\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $192\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $193\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $194\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $195\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $196\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $197\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $198\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $199\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $200\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $201\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $202\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $203\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $204\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $205\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $206\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $207\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $208\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $209\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $210\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $211\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $212\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $213\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $214\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $215\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $216\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $217\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $218\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $219\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $220\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $221\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $222\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $223\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $224\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $225\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $226\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $227\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $228\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $229\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $230\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $231\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $232\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $233\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $234\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $235\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $236\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $237\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $238\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $239\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $240\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $241\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $242\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $243\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $244\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $245\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $246\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $247\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $248\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $249\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $250\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $251\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $252\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $253\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $254\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $255\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
            "push $256\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $257\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $258\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $259\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $260\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $261\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $262\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $263\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $264\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $265\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $266\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $267\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $268\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $269\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $270\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $271\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $272\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $273\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $274\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $275\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $276\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $277\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $278\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $279\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $290\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $291\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $292\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $293\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $294\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $295\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $296\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $297\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $298\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $299\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $290\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $291\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $292\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $293\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $294\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $295\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $296\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $297\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $298\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $299\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $300\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $301\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $302\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $303\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $304\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $305\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $306\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $307\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $308\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $309\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $310\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $311\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $312\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $313\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $314\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $315\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $316\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $317\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $318\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $319\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $320\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $321\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $322\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $323\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $324\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $325\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $326\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $327\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $328\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $329\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $330\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $331\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $332\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $333\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $334\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $335\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $336\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $337\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $338\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $339\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $340\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $341\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $342\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $343\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $344\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $345\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $346\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $347\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $348\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $349\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $350\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $351\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $352\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $353\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $354\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $355\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $356\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $357\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $358\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $359\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $360\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $361\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $362\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $363\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $364\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $365\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $366\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $367\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $368\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $369\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $370\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $371\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $372\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $373\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $374\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $375\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $376\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $377\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $378\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $379\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $380\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $381\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $382\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $383\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $384\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $385\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $386\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $387\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $388\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $389\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $390\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $391\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $392\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $393\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $394\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $395\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $396\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $397\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $398\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $399\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $400\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $401\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $402\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $403\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $404\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $405\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $406\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $407\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $408\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $409\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $410\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $411\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $412\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $413\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $414\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $415\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $416\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $417\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $418\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $419\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $420\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $421\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $422\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $423\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $424\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $425\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $426\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $427\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $428\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $429\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $430\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $431\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $432\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $433\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $434\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $435\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $436\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $437\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $438\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $439\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $440\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $441\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $442\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $443\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $444\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $445\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $446\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $447\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $448\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $449\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $450\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $451\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $452\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $453\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $454\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $455\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $456\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $457\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $458\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $459\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $460\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $461\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $462\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $463\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $464\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $465\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $466\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $467\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $468\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $469\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $470\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $471\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $472\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $473\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $474\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $475\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $476\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $477\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $478\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $479\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $480\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $481\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $482\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $483\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $484\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $485\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $486\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $487\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $488\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $489\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $490\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $491\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $492\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $493\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $494\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $495\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $496\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $497\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $498\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $499\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $500\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $501\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $502\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $503\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $504\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $505\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $506\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $507\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $508\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $509\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $510\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
        "push $511\n\t"\
        "lea syscall_loader, %rax\n\t"\
        "add $33, %rax\n\t"\
        "jmp *%rax\n\t"\
     );


#define HOOK_START \
    __asm__ __volatile__ (\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
	"nop\n\t"\
        "pop %%rax\n\t"\
        "push %%rbp\n\t"\
        "mov %%rsp, %%rbp\n\t"\
        "sub $24, %%rsp\n\t"\
        "mov %%eax, %0\n\t"\
        "push %%rax\n\t"\
        "push %%rbx\n\t"\
        "push %%rcx\n\t"\
        "push %%rdx\n\t"\
        "push %%rsi\n\t"\
        "push %%rdi\n\t"\
        "push %%r8\n\t"\
        "push %%r9\n\t"\
        "push %%r10\n\t"\
        "push %%r11\n\t"\
        "push %%r12\n\t"\
        "push %%r13\n\t"\
        "push %%r14\n\t"\
        "push %%r15\n\t"\
        : "=a"(syscall_num)\
    );

#define HOOK_END \
    syscall_addr=((void**)syscall_table_backup)[syscall_num];\
    __asm__ __volatile__ (\
        "pop %%r15\n\t"\
        "pop %%r14\n\t"\
        "pop %%r13\n\t"\
        "pop %%r12\n\t"\
        "pop %%r11\n\t"\
        "pop %%r10\n\t"\
        "pop %%r9\n\t"\
        "pop %%r8\n\t"\
        "pop %%rdi\n\t"\
        "pop %%rsi\n\t"\
        "pop %%rdx\n\t"\
        "pop %%rcx\n\t"\
        "pop %%rbx\n\t"\
        "pop %%rax\n\t"\
        "xor %%rax, %%rax\n\t"\
        "mov %0, %%rax\n\t"\
        "mov %%rbp, %%rsp\n\t"\
        "pop %%rbp\n\t"\
        "jmp *%%rax\n\t"\
        :\
        :"m"(syscall_addr)\
    );
