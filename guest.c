#include <stddef.h>
#include <stdint.h>

static void outb(uint16_t port, uint8_t value) {
	asm("outb %0,%1" : /* empty */ : "a" (value), "Nd" (port) : "memory");
}

void
__attribute__((noreturn))
__attribute__((section(".start")))
_start(void) {
	const char *p;

	for (p = "Hello, world!\n"; *p; ++p)
		outb(0xE9, *p);

	*(long *) 0x400 = 42;

	outb(0xAA,0x12);

	asm volatile(
		"mov %%cr0,%%eax\n\t"
		:);
	for (;;)
		outb(0xE8,0xE8);	
		//asm("hlt" : /* empty */ : "a" (42) : "memory");
}
