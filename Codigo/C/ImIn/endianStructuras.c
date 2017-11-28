union endianness{
 short short_16;											// [______16______]
 unsigned char char_8[sizeof(short)] // [___8___][___8___];
}endianness;

endianness.short_16 = 0xFF00				 // 1111 1111 0000 0000 en binario;

(endianness.char_8[0] == 0x00 && endianness.char_8[1] == 0xFF)?
 printf("Little Endian\n");
 printf("Big Endian\n");