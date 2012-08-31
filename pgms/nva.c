#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAIL	1
#define CEIL(x, y) (x % y ? x / y + 1: x / y)


void usage()
{
	fprintf(stderr, "USAGE:\nhreverseImg x y\n x, y - horizonntal(x)"
		" Vertical(y) dimension of the image\nCreates a random image and does horizontal inversion.\n");	
	exit(FAIL);
}

typedef char byte;
struct pixelArr
{
	byte *p1, *p2;
};

typedef struct pixelArr pixelArr;

void random_fill_img(pixelArr *img, int x, int y)
{
	register int i, j;
	byte pixelval;
	srand(time(NULL));
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			pixelval = rand() % 4;
			printf("%d ", pixelval);
			if (pixelval & 1)
			{
				img[i].p1[j/8] |= 1<<(j % 8);
			}
			if (pixelval & 2)
			{
				img[i].p2[j/8] |= 1<<(j % 8);
			}
		}
		printf("\n");
	}
}


void print_img(pixelArr *img, int x, int y)
{
	register int i, j;
	byte pixelval = 0;
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			pixelval = 0;
			img[i].p1[j/8] & (1<<(j % 8))?pixelval|=1:0;
			img[i].p2[j/8] & (1<<(j % 8))?pixelval|=2:0;
			printf("%d-",pixelval);
			
		}
		printf("\n");
	}
}

void swap(byte *a, byte *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
}

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
	
void reverse_img(pixelArr *img, int x, int y)
{
	register int i, j;
	j = CEIL(x, 8) - 1;

	for (i = 0; i < y; i++)
	{
		int left, right;
		left = 0; right = j;

		while (left < right)
		{
			img[i].p1[left] = reverse_byte(img[i].p1[left]);
			img[i].p1[right] = reverse_byte(img[i].p1[right]);
			swap(&img[i].p1[left], &img[i].p1[right]);
			
			img[i].p2[left] = reverse_byte(img[i].p2[left]);
			img[i].p2[right] = reverse_byte(img[i].p2[right]);
			swap(&img[i].p2[left], &img[i].p2[right]);

			left++;
			right--;
		}
		if (left == right)
		{
			img[i].p1[left] = reverse_byte(img[i].p1[left]);
			img[i].p2[left] = reverse_byte(img[i].p2[left]);
		}
	}
}
			
	
main(int argc, char *argv[])
{
	int x, y;
	int i, j;
	
	pixelArr *img;

	if (argc != 3)
	{
		usage();
	}	
	sscanf(argv[1], "%d", &x);
	sscanf(argv[2], "%d", &y);

#ifdef WARN
	if (x % 8)
	{
		printf("The horizontal dimension(x) is not a multiple of 8\n");
	}
#endif
	img = (pixelArr *)malloc(sizeof(pixelArr) * y);
	int size = CEIL(x, 8);
	for (i = 0; i < y; i++)
	{
		img[i].p1 = (byte *)malloc(size);
		memset (img[i].p1, 0, size);
		img[i].p2 = (byte *)malloc(size);
		memset (img[i].p2, 0, size);
	}

	random_fill_img(img, x, y);
	print_img(img, x, y);
	printf("\n");
	reverse_img(img, x, y);
	print_img(img, x, y);
/*	for (i = 0; i < y; i++)
	{
		free(img[i].p1);
		free(img[i].p2);
	}
	free(img);
*/
	return SUCCESS;
} 

