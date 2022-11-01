#include <stdio.h>

int main(int argc, const char **argv)
{
  if (argc < 2)
    return 0;

  unsigned char table[256];
  FILE *f = fopen(argv[1], "rb");
  fread(table, 1, 256, f);
  fclose(f);
  const char rows[8] = "ABCDEFGH";
  const char cols[8] = "IJKLMNOP";
  for (int i = 0 ; i < 256 ; ++i)
  {
    if (table[i] != 0xff)
      //printf("  out_table['%c'] = ; // \n", i);
      /*printf("  out_table['%c'] = 0x%02x; // c=%02x table=%02x %c %c\n",
        i, table[i],
        i, // i < ' ' ? '.' : (char)i,
        table[i],
        rows[table[i] & 7],
        cols[table[i] >> 4]);
      */
      printf("%02x(%c) %02x %c %c\n",
        i, i < ' ' ? '.' : (char)i,
        table[i],
        rows[table[i] & 7],
        cols[table[i] >> 4]);
  }
}
