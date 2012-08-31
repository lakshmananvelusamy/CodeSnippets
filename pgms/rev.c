#include<stdio.h>
typedef char byte;
byte reverse_byte(byte a)
{
        int i = 0;
        byte r = 0;
        for (i = 0; i < 4; i++)
        {
                a & (1<<i) ? r |= (0x80)>>i : 0;
                a & (0x80>>i) ? r |= 1<<i : 0;
	}
	return r;

}

main()
{
	printf("%d %d", 0xc3, reverse_byte(0xb3));
}
