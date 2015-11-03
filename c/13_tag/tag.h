typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned char u8;
struct tag_header{
    u32 size;
    u32 tag;
};
struct tag {
    struct tag_header hdr;
    union {
        u8 a;
        u32 b;
        u64 c;
    }u;
};
