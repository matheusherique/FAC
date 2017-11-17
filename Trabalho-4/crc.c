#include <stdlib.h>
#include <stdio.h>

// ----------------------------- crc32b --------------------------------

/* This is the basic CRC-32 calculation with some optimization but no
table lookup. The the byte reversal is avoided by shifting the crc reg
right instead of left and by using a reversed 32-bit word to represent
the polynomial.
   When compiled to Cyclops with GCC, this function executes in 8 + 72n
instructions, where n is the number of bytes in the input message. It
should be doable in 4 + 61n instructions.
   If the inner loop is strung out (approx. 5*8 = 40 instructions),
it would take about 6 + 46n instructions. */

unsigned int crc32b(unsigned char *message) {
   int i, j;
   unsigned int byte, crc, mask;

   i = 0;
   crc = 0xFFFFFFFF;
   while (message[i] != 0) {
      byte = message[i];            // Get next byte.
      printf("byte = %#15X\n", byte);
      crc = crc ^ byte;
      printf("crc = %#15X\n", crc);
      printf("DIGItE ALGUMA COISA\n");
      getchar();
      for (j = 7; j >= 0; j--) {    // Do eight times.
         mask = -(crc & 1);
         printf("mask = %#15X\n", mask);
         
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
         printf(" crc = (crc >> 1) ^ (0xEDB88320 & mask) = %#15X\n", crc);
         printf("DIGItE ALGUMA COISA\n");
         getchar();
         printf("=====================================\n");
      }
      i = i + 1;
      printf("=====================================\n");
   }
   return ~crc;
}

int main() {
    char *c;
    c = "Alo mundo.";
    unsigned int result;
    result = crc32b(c);
    printf("result = %#15X\n", result);
    unsigned int abc = -(10);
    printf("abc = %d\n",abc);
    return 0;
}
