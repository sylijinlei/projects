#include <stdio.h>
#include <malloc.h>
#include "tag.h"
struct tag *param;
void setup_start_tag(void)
{
    param = (struct tag*)malloc(sizeof(struct tag));
	param->hdr.tag = 1;
	param->hdr.size = 1;
    param->u.a = 1;

	/*params = tag_next (params);*/
}
int main(int argc, char *argv[])
{
    printf("header size = %d\n", (int)sizeof(struct tag_header));
    printf("tag size = %d\n", (int)sizeof(struct tag));
    setup_start_tag();
    param += 100;

    return 0;
}
