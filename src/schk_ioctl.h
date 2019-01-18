#define SCHK_MAGIC_NUMBER 's'
#define SCHK_CMD_SET_FLAG _IOW(SCHK_MAGIC_NUMBER,0,unsigned long long)
#define SCHK_CMD_GET_FLAG _IOW(SCHK_MAGIC_NUMBER,1,unsigned long long)

#define SCHK_FLAG_INHERIT 2
#define SCHK_FLAG_ENABLE 1
#define SCHK_FLAG_ENABLE_ON_EXEC 4