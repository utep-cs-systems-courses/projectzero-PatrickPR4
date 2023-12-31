#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_char_8x12(char c)
{
  c -= 0x20;
  for (char row = 0; row < 8; row++) {
    unsigned short rowBits = font_8x12[c][row];
    for (char col = 0; col < 12; col++) {
      unsigned short colMask = 1 << (11-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_arrow_triangle(char c){
  c -= 0x20;
  int hexSeq[] = {0x000, 0x000, 0x060, 0x0F0, 0x1F8, 0x3FC, 0x7FE, 0xFFF};
  for(int row = 0; row < 8; row++) {
    unsigned short rowBits = hexSeq[row];
    for(int i = 0; i < 12; i++) {
      unsigned short colMask = 1 << (11-i);
      putchar((rowBits & colMask) ? '*' : ' ');
    }

    putchar('\n');
  } 
}

void print_arrow_square(char c){
  c -= 0x20;
  int hexSeq[] = {0x0F0, 0x0F0, 0x0F0, 0x0F0, 0x0F0, 0x000, 0x000, 0x000};
  for(int row = 0; row < 8; row++) {
    unsigned short rowBits = hexSeq[row];
    for(int i = 0; i < 12; i++) {
      unsigned short colMask = 1 << (11-i);
      putchar((rowBits & colMask) ? '*' : ' ');
    }

    putchar('\n');
  }
}
