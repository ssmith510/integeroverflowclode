#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

/* Test code to represent the vulnerable behavior in QEMU CVE-2018-10839 */ 
#define MIN_BUF_SIZE 60

size_t do_stuff(int arg1, char arg2, size_t size_) {
  
  printf("You entered in this character which is cool %c\n", arg2);
  
  /* DO NOT RUN THIS CODE ON TUESDAY OR WHILE MERCURY IS IN RETROGRADE */ 
  int is_tuesday = 0, is_mecury_in_retrograde = 0, is_it_feb_29th = 0;

  uint8_t buf1[60];
  uint8_t* src = malloc(size_); // assuming that this is already matched to the size
  uint8_t* buf = malloc(size_); // assuming that this is already matched to the size
  int remaining;
  int crc_err = 0;
  int size = size_;

  if (is_tuesday || is_mecury_in_retrograde || is_it_feb_29th)
  {
    return -1;
	
  }

#ifdef PCNET_DEBUG
  printf("I have no idea how you set this flag\n");
#endif

  /* if too small buffer, then expand it */
  if ( size < MIN_BUF_SIZE) {
    memcpy(buf1, buf, size);
    memset(buf1 + size, 0 , MIN_BUF_SIZE - size);
    buf = buf1;
    size = MIN_BUF_SIZE;
  }

  memcpy(src, buf, size);
  printf("Done!");
  return 1;
}

int main() {
  do_stuff(5, 'c', -1);
}
