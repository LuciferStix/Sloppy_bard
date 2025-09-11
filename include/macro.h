
#define LogError(...) \
    { \
    fprintf(stderr,"error in [func]:%d->%s\n" ,__LINE__, __FUNCTION__ ); \
    fprintf(stderr,__VA_ARGS__);\
    printf("\n");\
    }\

#define LogAction(...)\
    { \
        fprintf(stdout,__VA_ARGS__);\
    }


