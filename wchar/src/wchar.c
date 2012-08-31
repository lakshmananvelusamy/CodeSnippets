/*
 ============================================================================
 Name        : wchar.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main(void)
{
	int i;
setlocale(LC_ALL, "");


const char *narrow = "Test Unicode (narrow): Ã¯Ã Ã½ ÐÐ¾Ñ ã‘ãŸã„ã¨é¡˜ã†!\n";
fprintf(stdout, "%s\n", narrow);

fprintf(stdout, "Narrow bytes:\n");
for (i = 0; i< strlen(narrow); ++i)
fprintf(stdout, "%3d: %02X\n", i, (unsigned int) *((unsigned char *)narrow+i));

if (fwide (stderr, 1) <= 0)
fprintf(stdout, "Failed to set stderr to wide orientation\n");

const wchar_t *wide = L"Test Unicode (wide): Ã¯Ã Ã½ ÐÐ¾Ñ ã‘ãŸã„ã¨é¡˜ã†!\n";
fwprintf(stderr, L"\n%ls\n", wide);

fwprintf(stderr, L"\nNarrow-to-wide: %s\n", narrow);

fprintf(stdout, "\nWide-to-narrow: %ls\n", wide);

fprintf(stdout, "Wide bytes:\n");
for (i = 0; i< (wcslen(wide) * sizeof(wchar_t)); ++i)
fprintf(stdout, "%3d: %02X\n", i, (unsigned int) *((unsigned char *)wide+i));

return 0;
}
