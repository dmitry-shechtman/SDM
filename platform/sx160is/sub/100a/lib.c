#include "platform.h"

char *hook_raw_image_addr() {
    return (char*) 0x420F6420; //Found @0xffb5a2f4  search for "BJPEG BUFF"
}

char *hook_alt_raw_image_addr() {
    return (char*) 0x420F6420; //Found @0xffb5a2f4  search for "BJPEG BUFF"
}

long hook_raw_size()
{ return 0x01794300; }                    // Found @0xffb5a348


