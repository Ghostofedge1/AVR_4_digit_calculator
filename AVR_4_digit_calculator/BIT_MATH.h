#define CLR_BIT(ADDR,BIT) (ADDR &= ~(1<<BIT))
#define SET_BIT(ADDR,BIT) (ADDR |= (1<<BIT))
#define TGL_BIT(ADDR,BIT) (ADDR ^= (1<<BIT))
#define GET_BIT(ADDR,BIT) ((ADDR & (1<<BIT))>>BIT)