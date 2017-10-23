static const char msg[] = "Hello, world";

void putchar (int c){
  
}

void main(void) {
  const char *ptr = msg;
  while (*ptr)
    putchar (*ptr++);
  while (1);

}
