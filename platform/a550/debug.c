
#include <stdlib.h>
#include <conf.h>

void dbg_log(char *str);

#define LED_PR 0xc0220084

static void blink(int cnt)
{
	volatile long *p=(void*)LED_PR;
	int i;

	for(;cnt>0;cnt--){
		p[0]=0x46;

		for(i=0;i<0x200000;i++){
			asm ("nop\n");
			asm ("nop\n");
		}
		p[0]=0x44;
		for(i=0;i<0x200000;i++){
			asm ("nop\n");
			asm ("nop\n");
		}
	}
}

#define ROMSIZE (4*1024*1024)

static int dbg_fh = 0;

void dbg_start() {
  if (0 == dbg_fh) {
    if ((dbg_fh = open("A/MISC/DEBUG.LOG", O_WRONLY|O_CREAT, 0777)) > 0) {
      lseek(dbg_fh, 0, SEEK_END);
    }
  }
}

void dbg_stop() {

  
  if (dbg_fh > 0) {
    close(dbg_fh);
    dbg_fh = 0;
  }
}

void dbg_log(char *str) {
  blink(2);
  if (dbg_fh > 0) {
    write(dbg_fh, str, strlen(str));
  }
}

static int dump_rom() {
  volatile int ret = 0;
  volatile int fd;

  if ((fd  = open("A/MISC/FW_FFC0.DMP", O_WRONLY|O_CREAT, 0777)) > 0) {
    write(fd, (char*)0xFFC00000, ROMSIZE);
    close(fd);
    ret = 1;
  }

  return ret;
}

void go_debug(long kbd_state[]) {



}


