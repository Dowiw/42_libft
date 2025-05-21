#include "libft.h"
#include <assert.h>
#include <stdio.h> //Printing
#include <limits.h> //Mins and Maxes
#include <strings.h> //String functions
#include <string.h> //More string functions
#include <ctype.h> //Type checking
#include <bsd/string.h> // strlcat, bzero, strlcpy

void	atoi_tester(void);
void	bzero_tester(void);
void	calloc_tester(void);
void	isalnum_tester(void);
void	isalpha_tester(void);

void	isascii_tester(void);
void	isdigit_tester(void);
void	isprint_tester(void);
void	memchr_tester(void);
void	memcmp_tester(void);

void	memcpy_tester(void);
void	memmove_tester(void);
void	memset_tester(void);
void	strchr_tester(void);
void	strdup_tester(void);

void	strlcat_tester(void);
void	strlcpy_tester(void);
void	strlen_tester(void);
void	strncmp_tester(void);
void	strnstr_tester(void);

void	strrchr_tester(void);
void	tolower_tester(void);
void	toupper_tester(void);

int main(void)
{
	//testing happens from A to Z
	atoi_tester();
	bzero_tester();
	calloc_tester();
	isalnum_tester();
	isalpha_tester();
	isascii_tester();
	isdigit_tester();
	isprint_tester();

	//None of these have memory overlap checking, may return error
	memchr_tester();
	memcmp_tester();
	memcpy_tester();

	//This one has overlap checking
	memmove_tester();

	memset_tester();
	strchr_tester();
	strdup_tester();

	//For compilation, must use -lbsd
	strlcat_tester();
	strlcpy_tester();

	strncmp_tester();
	strnstr_tester();
	strrchr_tester();
	tolower_tester();
	toupper_tester();
	return (0);
}

void	atoi_tester(void)
{
	printf("Testing ft_atoi against atoi...  \n");
	assert(ft_atoi("") == atoi("")); //Empty
	assert(ft_atoi("   ") == atoi("   ")); //Empty
	assert(ft_atoi("123   ") == atoi("123   ")); //isspace after
	assert(ft_atoi("   123") == atoi("   123")); //isspace before

	//One sign
	assert(ft_atoi("+123") == atoi("+123"));
	assert(ft_atoi("-123") == atoi("-123"));

	//Two signs
	assert(ft_atoi("--123") == atoi("--123"));
	assert(ft_atoi("++123") == atoi("++123"));
	assert(ft_atoi("+-123") == atoi("+-123"));

	//Non-digit
	assert(ft_atoi("123abc") == atoi("123abc"));
	assert(ft_atoi("abc123") == atoi("abc123"));
	assert(ft_atoi("+ 123") == atoi("+ 123"));
	assert(ft_atoi("12 34") == atoi("12 34"));

	//Overflow/underflow
	assert(ft_atoi("2147483647") == atoi("2147483647"));
	assert(ft_atoi("2147483648") == atoi("2147483648"));
	assert(ft_atoi("-2147483648") == atoi("-2147483648"));
	assert(ft_atoi("-2147483649") == atoi("-2147483649"));

	//Sign
	assert(ft_atoi("+") == atoi("+"));
	assert(ft_atoi("-") == atoi("-"));

	//Null
	assert(ft_atoi("\0") == atoi("\0"));

	//Leading zeros
	assert(ft_atoi("0000123") == atoi("0000123"));

	//Numeric split
	assert(ft_atoi("12x34") == atoi("12x34"));

	//Non-numeric
	assert(ft_atoi("abc") == atoi("abc"));
	assert(ft_atoi("   abc") == atoi("   abc"));

	//Sign after whitespace
	assert(ft_atoi("   -42") == atoi("   -42"));

	//Signs with spaces
	assert(ft_atoi("+ 42") == atoi("+ 42"));
	assert(ft_atoi("- 42") == atoi("- 42"));

	//Tabs and others
	assert(ft_atoi("\t\n 42") == atoi("\t\n 42"));

	printf("You're ft_atoi works!\n");
}

void	bzero_tester(void)
{
	printf("Testing ft_bzero against bzero...  \n");
	char buf1[10], buf2[10];

	//Zero length
	memset(buf1, 123, sizeof(buf1));
	memset(buf2, 123, sizeof(buf2));
	ft_bzero(buf1, (0));
	bzero(buf2, (0));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//NULL pointer with zero length (may crash if not guarded)
	//ft_bzero(NULL, 0);
	//bzero(NULL, 0);

	//Small buffer
	memset(buf1, 255, sizeof(buf1));
	memset(buf2, 255, sizeof(buf2));
	ft_bzero(buf1, 1);
	bzero(buf2, 1);
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Full buffer
	memset(buf1, 66, sizeof(buf1));
	memset(buf2, 66, sizeof(buf2));
	ft_bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Unaligned memory
	memset(buf1, 17, sizeof(buf1));
	memset(buf2, 17, sizeof(buf2));
	ft_bzero(buf1 + 1, 5);
	bzero(buf2 + 1, 5);
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Already zeroed buffer
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));
	ft_bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Non-zero initialized buffer
	memset(buf1, 0x77, sizeof(buf1));
	memset(buf2, 0x77, sizeof(buf2));
	ft_bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);
	printf("You're bzero works!\n");
}

void	calloc_tester(void)
{
	printf("Testing ft_calloc against calloc...  \n");
	//Zero elements
	void *sys_zero_elem = calloc(0, sizeof(int));
	void *ft_zero_elem  = ft_calloc(0, sizeof(int));
	assert((sys_zero_elem == NULL && ft_zero_elem == NULL) || (sys_zero_elem != NULL && ft_zero_elem != NULL));
	free(sys_zero_elem);
	free(ft_zero_elem);

	//Zero size
	void *sys_zero_size = calloc(10, 0);
	void *ft_zero_size  = ft_calloc(10, 0);
	assert((sys_zero_size == NULL && ft_zero_size == NULL) || (sys_zero_size != NULL && ft_zero_size != NULL));
	free(sys_zero_size);
	free(ft_zero_size);

	//Regular allocation
	size_t n = 20;
	sys_zero_elem = calloc(n, sizeof(int));
	ft_zero_elem  = ft_calloc(n, sizeof(int));
	assert((sys_zero_elem == NULL && ft_zero_elem == NULL) || (sys_zero_elem != NULL && ft_zero_elem != NULL));
	if (sys_zero_elem && ft_zero_elem) {
		assert(memcmp(sys_zero_elem, ft_zero_elem, n * sizeof(int)) == 0);
	}
	free(sys_zero_elem);
	free(ft_zero_elem);

	//Integer overflow (return NULL)
	size_t huge = SIZE_MAX / 2 + 1;
	sys_zero_elem = calloc(huge, 2);
	ft_zero_elem  = ft_calloc(huge, 2);
	assert((sys_zero_elem == NULL && ft_zero_elem == NULL) || (sys_zero_elem != NULL && ft_zero_elem != NULL));
	free(sys_zero_elem);
	free(ft_zero_elem);

	//Alignment check (ensure no crash)
	sys_zero_elem = calloc(4, sizeof(double));
	ft_zero_elem  = ft_calloc(4, sizeof(double));
	assert((sys_zero_elem == NULL && ft_zero_elem == NULL) || (sys_zero_elem != NULL && ft_zero_elem != NULL));
	free(sys_zero_elem);
	free(ft_zero_elem);
	printf("You're calloc works!\n");
}

void	isalnum_tester(void)
{
	printf("Testing ft_isalnum against isalnum...  \n");

	//isalnum is so weird for return 8
	//Alphabets && Numbers
	assert((ft_isalnum('0') && isalnum('0')) != 0);
	assert((ft_isalnum('9') && isalnum('9')) != 0);
	assert((ft_isalnum('a') && isalnum('a')) != 0);
	assert((ft_isalnum('z') && isalnum('z')) != 0);
	assert((ft_isalnum('A') && isalnum('A')) != 0);
	assert((ft_isalnum('Z') && isalnum('Z')) != 0);

	//Middle
	assert((ft_isalnum('j') && isalnum('j')) != 0);
	assert((ft_isalnum('K') && isalnum('K')) != 0);
	assert((ft_isalnum('5') && isalnum('5')) != 0);

	//Space
	assert((ft_isalnum(' ') && isalnum(' ')) == 0);
	assert((ft_isalnum('\n') && isalnum('\n')) == 0);
	assert((ft_isalnum('\r') && isalnum('\r')) == 0);

	//Null
	assert((ft_isalnum('\0') && isalnum('\0')) == 0);
	printf("You're isalnum works!\n");
}

void	isalpha_tester(void)
{
	printf("Testing ft_isalpha against isalpha...  \n");

	//Alphabets
	assert((ft_isalpha('a') && isalpha('a')) != 0);
	assert((ft_isalpha('A') && isalpha('A')) != 0);
	assert((ft_isalpha('z') && isalpha('z')) != 0);
	assert((ft_isalpha('Z') && isalpha('Z')) != 0);
	assert((ft_isalpha('M') && isalpha('M')) != 0);
	assert((ft_isalpha('n') && isalpha('n')) != 0);

	//Non-alphabets
	assert((ft_isalpha('1') && isalpha('1')) == 0);
	assert((ft_isalpha('>') && isalpha('>')) == 0);
	assert((ft_isalpha('?') && isalpha('?')) == 0);

	//Space
	assert((ft_isalpha(' ') && isalpha(' ')) == 0);
	assert((ft_isalpha('\n') && isalpha('\n')) == 0);
	assert((ft_isalpha('\r') && isalpha('\r')) == 0);

	//Null
	assert((ft_isalpha('\0') && isalpha('\0')) == 0);

	printf("You're isalpha works!\n");
}

void	isascii_tester(void)
{
	printf("Testing ft_isascii against isascii...  \n");

	//Alphabets
	assert((ft_isascii('a') && isascii('a')) != 0);
	assert((ft_isascii('A') && isascii('A')) != 0);
	assert((ft_isascii('z') && isascii('z')) != 0);
	assert((ft_isascii('Z') && isascii('Z')) != 0);
	assert((ft_isascii('M') && isascii('M')) != 0);
	assert((ft_isascii('n') && isascii('n')) != 0);

	//Non-alphabets
	assert((ft_isascii('1') && isascii('1')) != 0);
	assert((ft_isascii('>') && isascii('>')) != 0);
	assert((ft_isascii('?') && isascii('?')) != 0);

	//Edge-cases
	assert((ft_isascii('\0') && isascii('\0')) != 0);
	assert((ft_isascii('\177') && isascii('\177')) != 0); //DEL char in octal

	//Space
	assert((ft_isascii(' ') && isascii(' ')) != 0);
	assert((ft_isascii('\n') && isascii('\n')) != 0);
	assert((ft_isascii('\r') && isascii('\r')) != 0);

	//Outside ascii
	assert((ft_isascii(-1) && isascii(-1)) == 0);
	assert((ft_isascii(128) && isascii(128)) == 0);
	assert((ft_isascii(INT_MIN) && isascii(INT_MIN)) == 0);
	assert((ft_isascii(INT_MAX) && isascii(INT_MAX)) == 0);

	printf("You're isascii works!\n");
}

void	isdigit_tester(void)
{
	printf("Testing ft_isdigit against isdigit...  \n");

	//Numbers
	assert((ft_isdigit('0') && isdigit('0')) != 0);
	assert((ft_isdigit('9') && isdigit('9')) != 0);
	assert((ft_isdigit('5') && isdigit('5')) != 0);
	assert((ft_isdigit('3') && isdigit('3')) != 0);
	assert((ft_isdigit('7') && isdigit('7')) != 0);

	//Alphabets
	assert((ft_isdigit('a') && isdigit('a')) == 0);
	assert((ft_isdigit('A') && isdigit('A')) == 0);
	assert((ft_isdigit('z') && isdigit('z')) == 0);
	assert((ft_isdigit('Z') && isdigit('Z')) == 0);
	assert((ft_isdigit('M') && isdigit('M')) == 0);
	assert((ft_isdigit('n') && isdigit('n')) == 0);

	//Non-alphabets
	assert((ft_isdigit('>') && isdigit('>')) == 0);
	assert((ft_isdigit('?') && isdigit('?')) == 0);

	//Space
	assert((ft_isdigit(' ') && isdigit(' ')) == 0);
	assert((ft_isdigit('\n') && isdigit('\n')) == 0);
	assert((ft_isdigit('\r') && isdigit('\r')) == 0);

	//Null
	assert((ft_isdigit('\0') && isdigit('\0')) == 0);

	//Outside ascii
	assert((ft_isdigit(-1) && isdigit(-1)) == 0);
	assert((ft_isdigit(128) && isdigit(128)) == 0);
	assert((ft_isdigit(INT_MIN) && isdigit(INT_MIN)) == 0);
	assert((ft_isdigit(INT_MAX) && isdigit(INT_MAX)) == 0);

	printf("You're isdigit works!\n");
}

void	isprint_tester(void)
{
	printf("Testing ft_isprint against isprint...  \n");

	//Numbers
	assert((ft_isprint('0') && isprint('0')) != 0);
	assert((ft_isprint('9') && isprint('9')) != 0);
	assert((ft_isprint('5') && isprint('5')) != 0);
	assert((ft_isprint('3') && isprint('3')) != 0);
	assert((ft_isprint('7') && isprint('7')) != 0);

	//Alphabets
	assert((ft_isprint('a') && isprint('a')) != 0);
	assert((ft_isprint('A') && isprint('A')) != 0);
	assert((ft_isprint('z') && isprint('z')) != 0);
	assert((ft_isprint('Z') && isprint('Z')) != 0);
	assert((ft_isprint('M') && isprint('M')) != 0);
	assert((ft_isprint('n') && isprint('n')) != 0);

	//Non-alphabets
	assert((ft_isprint('>') && isprint('>')) != 0);
	assert((ft_isprint('?') && isprint('?')) != 0);

	//Space
	assert((ft_isprint(' ') && isprint(' ')) != 0);
	assert((ft_isprint('\n') && isprint('\n')) == 0);
	assert((ft_isprint('\r') && isprint('\r')) == 0);

	//Null
	assert((ft_isprint('\0') && isprint('\0')) == 0);

	//Outside ascii
	assert((ft_isprint(-1) && isprint(-1)) == 0);
	assert((ft_isprint(128) && isprint(128)) == 0);
	assert((ft_isprint(INT_MIN) && isprint(INT_MIN)) == 0);
	assert((ft_isprint(INT_MAX) && isprint(INT_MAX)) == 0);

	printf("You're isprint works!\n");
}

void	memchr_tester(void)
{
	printf("Testing ft_memchr against memchr...  \n");

	//Regular Case
	char s1[] = "Hello World";
	char find = 'W';
	char *out1 = ft_memchr(s1, find, sizeof(s1));
	char *out2 = memchr(s1, find, sizeof(s1));
	assert(*out1 == *out2); //Should return W

	//Look for Null Case
	char s2[] = "Hello \0World";
	char find2 = '\0';
	char *out3 = ft_memchr(s2, find2, sizeof(s2));
	char *out4 = memchr(s2, find2, sizeof(s2));
	assert(*out3 == *out4); //Should return '\0'

	//Look for ' '
	char s3[] = "Hello World";
	char find3 = ' ';
	char *out5 = ft_memchr(s3, find3, sizeof(s3));
	char *out6 = memchr(s3, find3, sizeof(s3));
	assert(*out5 == *out6); //Should return ' '

	//Not found
	char s4[] = "Hello World";
	char find4 = 'x';
	char *out7 = ft_memchr(s4, find4, sizeof(s4));
	char *out8 = memchr(s4, find4, sizeof(s4));
	assert(out7 == out8); // Both should return NULL

	//0 length
	char s5[] = "Hello World";
	char find5 = 'H';
	char *out9 = ft_memchr(s5, find5, 0);
	char *out10 = memchr(s5, find5, 0);
	assert(out9 == out10); // Should both be NULL

	//Length not enough
	char s6[] = "Hello World";
	char find6 = 'W';
	char *out11 = ft_memchr(s6, find6, 5); // Only checks "Hello"
	char *out12 = memchr(s6, find6, 5);
	assert(out11 == out12); // Should both be NULL

	//Check for unsigned property
	unsigned char s7[] = {0x01, 0x80, 0xFF, 0x00};
	unsigned char find7 = 0xFF;
	unsigned char *out13 = ft_memchr(s7, find7, sizeof(s7));
	unsigned char *out14 = memchr(s7, find7, sizeof(s7));
	assert(out13 == out14);

	//Check for multiple
	char s8[] = "aabbccbb";
	char find8 = 'b';
	char *out15 = ft_memchr(s8, find8, sizeof(s8));
	char *out16 = memchr(s8, find8, sizeof(s8));
	assert(out15 == out16); // Should point to the first 'b'

	//Look for null at string end, not outside string
	char s9[] = "abc";
	char find9 = '\0';
	char *out17 = ft_memchr(s9, find9, 10);
	char *out18 = memchr(s9, find9, 10);
	assert(out17 == out18); // Should point to '\0' at end of string
	// printf("%c", *(out17 - 1));
	// printf("%c", *(out18 - 1));

	//Return the first x
	char s10[10];
	memset(s10, 'x', 10);
	char *out19 = ft_memchr(s10, 'x', 10);
	char *out20 = memchr(s10, 'x', 10);
	assert(out19 == out20); //Should point to same starting x

	//Arbitary array
	char s11[] = {-1, 1, 2, 3};
	char *out21 = ft_memchr(s11, -1, 4);
	char *out22 = memchr(s11, -1, 4);
	assert(out21 == out22); //Should return pointer to -1
	// printf("%i\n", *out21);
	// printf("%i\n", *out22);

	printf("You're memchr works!\n");
}

void	memcmp_tester(void)
{
	printf("Testing ft_memcmp against memcmp...  \n");

	//From what I know, memcmp just returns a subtraction between the characters
	char s1[] = "Hello World"; //Main string

	char s2[] = "Hello World";
	char s3[] = "Jello World";
	char s4[] = "Hello Xorld";
	char s5[] = "Hello Worlz";
	char s6[] = "Differ!";

	//Regular case: identical strings
	assert(ft_memcmp(s1, s2, sizeof(s1)) == memcmp(s1, s2, sizeof(s1)));

	//Different at the start
	assert(ft_memcmp(s1, s3, sizeof(s1)) == memcmp(s1, s3, sizeof(s1)));

	//Different in the middle
	assert(ft_memcmp(s1, s4, sizeof(s1)) == memcmp(s1, s4, sizeof(s1)));

	//Different at the end
	assert(ft_memcmp(s1, s5, sizeof(s1)) == memcmp(s1, s5, sizeof(s1)));

	//n = 0 (should return 0 even if the strings are different)
	assert(ft_memcmp(s1, s6, 0) == memcmp(s1, s6, 0));

	//n < length, diff after n
	assert(ft_memcmp(s1, s3, 1) == memcmp(s1, s3, 1));
	// printf("%i, %i", ft_memcmp(s1, s3, 1), memcmp(s1, s3, 1));
	assert(ft_memcmp(s1, s4, 6) == memcmp(s1, s4, 6));

	//n > strlen, check beyond null terminator
	char s7[] = "Hello";
	char s8[] = "Hello";
	assert(ft_memcmp(s7, s8, 10) == memcmp(s7, s8, 10));

	//Compare buffers containing '\0' (likely to return error)
	char s9[] = "abc\0def";
	char s10[] = "abc\0xyz";
	assert(ft_memcmp(s9, s10, 7) == memcmp(s9, s10, 7));

	//Compare single bytes
	char s11[] = "A";
	char s12[] = "B";
	assert(ft_memcmp(s11, s12, 1) == memcmp(s11, s12, 1));
	//printf("%i, %i", ft_memcmp(s11, s12, 1), memcmp(s11, s12, 1));

	//Compare non-ASCII bytes
	unsigned char s13[] = {0xFF, 0x00, 0x80};
	unsigned char s14[] = {0xFF, 0x00, 0x81};
	assert(ft_memcmp(s13, s14, 3) == memcmp(s13, s14, 3));

	printf("You're memcmp works!\n");
}

void	memcpy_tester(void)
{
	printf("Testing ft_memcpy against memcpy...  \n");

	char s1[] = "Hello World";
	char buf1[20], buf2[20];

	//Memcmp to return 0 if equal
	//Regular case: copy string
	memcpy(buf1, s1, sizeof(s1));
	ft_memcpy(buf2, s1, sizeof(s1));
	assert(memcmp(buf1, buf2, sizeof(s1)) == 0);

	//Copy partial buffer
	memset(buf1, 0, sizeof(buf1)); //Re-empty buffers
	memset(buf2, 0, sizeof(buf2));

	memcpy(buf1, s1, 5);
	ft_memcpy(buf2, s1, 5);
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Copy with n = 0
	memcpy(buf1, s1, 0);
	ft_memcpy(buf2, s1, 0);
	// printf("%s, %s", buf1, buf2);
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0); //Should have hello from previous

	//Copy buffer with nulls
	char s2[] = {'a', 'b', '\0', 'c', 'd'};
	memcpy(buf1, s2, sizeof(s2));
	ft_memcpy(buf2, s2, sizeof(s2));
	// printf("%s, %s, %c, %c", buf1, buf2, buf1[3], buf2[3]); // Should print ab only
	assert(memcmp(buf1, buf2, sizeof(s2)) == 0);

	//Copy non-ASCII bytes
	unsigned char s3[] = {0xFF, 0x00, 0x7F, 0x80};
	memcpy(buf1, s3, sizeof(s3));
	ft_memcpy(buf2, s3, sizeof(s3));
	assert(memcmp(buf1, buf2, sizeof(s3)) == 0);

	//Copy to same address
	memcpy(buf1, buf1, sizeof(buf1));
	ft_memcpy(buf2, buf2, sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	printf("You're memcpy works!\n");
}

void	memmove_tester(void)
{
	printf("Testing ft_memmove against memmove...\n");

	//Regular case: copy string
	char s1[] = "Hello World";
	char buf1[20], buf2[20];

	memmove(buf1, s1, sizeof(s1));
	ft_memmove(buf2, s1, sizeof(s1));
	assert(memcmp(buf1, buf2, sizeof(s1)) == 0);

	//Copy partial buffer
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));

	memmove(buf1, s1, 5); // Only hello
	ft_memmove(buf2, s1, 5);
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Copy with n = 0
	memmove(buf1, s1, 0);
	ft_memmove(buf2, s1, 0);
	// printf("%s, %s", buf1, buf2);
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Copy buffer with nulls
	char s2[] = {"ab\0cd"};
	memmove(buf1, s2, sizeof(s2));
	ft_memmove(buf2, s2, sizeof(s2));
	//printf("%s, %s", buf1, buf2);
	assert(memcmp(buf1, buf2, sizeof(s2)) == 0);

	//Copy non-ASCII bytes
	unsigned char s3[] = {0xFF, 0x00, 0x7F, 0x80};
	memmove(buf1, s3, sizeof(s3));
	ft_memmove(buf2, s3, sizeof(s3));
	assert(memcmp(buf1, buf2, sizeof(s3)) == 0);

	//Copy to same address
	memmove(buf1, buf1, sizeof(buf1));
	ft_memmove(buf2, buf2, sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Overlapping: src before dst
	char s4[] = "123456789";
	memmove(s4+2, s4, 7);
	char s5[] = "123456789";
	ft_memmove(s5+2, s5, 7);
	assert(memcmp(s4, s5, 9) == 0);

	//Overlapping: dst before src
	char s6[] = "abcdefghi";
	memmove(s6, s6+2, 7);
	char s7[] = "abcdefghi";
	ft_memmove(s7, s7+2, 7);
	assert(memcmp(s6, s7, 9) == 0);

	printf("You're memmove works!\n");
}

void	memset_tester(void)
{
	printf("Testing ft_memset against memset...\n");

	char buf1[20], buf2[20];

	//Regular case: fill buffer with a char
	memset(buf1, 'A', sizeof(buf1));
	ft_memset(buf2, 'A', sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Set n = 0
	memset(buf1, 'B', (0));
	ft_memset(buf2, 'B', 0);
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Set partial buffer
	memset(buf1, 'C', 5);
	ft_memset(buf2, 'C', 5);
	assert(memcmp(buf1, buf2, 5) == 0);

	//Set buffer with 0
	memset(buf1, 0, sizeof(buf1));
	ft_memset(buf2, 0, sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Set buffer with non-ascii using unsigned char (e.g., 0xFF)
	memset(buf1, 0xFF, sizeof(buf1));
	ft_memset(buf2, 0xFF, sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Set buffer with value > 127
	memset(buf1, 200, sizeof(buf1));
	ft_memset(buf2, 200, sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);

	//Set single byte
	memset(buf1, 'Z', 1);
	ft_memset(buf2, 'Z', 1);
	assert(memcmp(buf1, buf2, 1) == 0);

	printf("You're memset works!\n");
}

void	strchr_tester(void)
{
	printf("Testing ft_strchr against strchr...\n");

	//Regular case: find character in string
	char s1[] = "Hello World";
	char find1 = 'W';
	char *out1 = ft_strchr(s1, find1);
	char *out2 = strchr(s1, find1);
	assert(out1 == out2); //Pointer to W

	//Find first character
	char find2 = 'H';
	char *out3 = ft_strchr(s1, find2);
	char *out4 = strchr(s1, find2);
	assert(out3 == out4); //Pointer to H

	//Find last character
	char find3 = 'd';
	char *out5 = ft_strchr(s1, find3);
	char *out6 = strchr(s1, find3);
	assert(out5 == out6); //Pointer to d

	//Find null terminator
	char find4 = '\0';
	char *out7 = ft_strchr(s1, find4);
	char *out8 = strchr(s1, find4);
	assert(out7 == out8); //Pointer to '\0'

	//Character not found
	char find5 = 'x';
	char *out9 = ft_strchr(s1, find5);
	char *out10 = strchr(s1, find5);
	assert(out9 == out10); //Return NULL

	//String with repeated character, should return first
	char s2[] = "banana";
	char find6 = 'a';
	char *out11 = ft_strchr(s2, find6);
	char *out12 = strchr(s2, find6);
	assert(out11 == out12); //Pointer to first 'a'

	char s3[] = "";

	//Empty string, searching for anything but '\0'
	char find7 = 'Q';
	char *out13 = ft_strchr(s3, find7);
	char *out14 = strchr(s3, find7);
	assert(out13 == out14); //Return NULL

	//Empty string, searching for '\0'
	char find8 = '\0';
	char *out15 = ft_strchr(s3, find8);
	char *out16 = strchr(s3, find8);
	assert(out15 == out16); // Return pointer to '\0'

	printf("You're strchr works!\n");
}

void	strdup_tester(void)
{
	printf("Testing ft_strdup against strdup...\n");

	//Regular case: duplicate string
	char s1[] = "Hello World";
	char *out1 = ft_strdup(s1);
	char *out2 = strdup(s1);
	assert(strcmp(out1, out2) == 0);
	free(out1);
	free(out2);

	//Empty string
	char s2[] = "";
	char *out3 = ft_strdup(s2);
	char *out4 = strdup(s2);
	assert(strcmp(out3, out4) == 0);
	free(out3);
	free(out4);

	//String with embedded nulls (should stop at first null)
	char s3[] = "abc\0def";
	char *out5 = ft_strdup(s3);
	char *out6 = strdup(s3);
	assert(strcmp(out5, out6) == 0);
	free(out5);
	free(out6);

	//Single character string
	char s4[] = "Z";
	char *out7 = ft_strdup(s4);
	char *out8 = strdup(s4);
	assert(strcmp(out7, out8) == 0);
	free(out7);
	free(out8);

	printf("You're strdup works!\n");
}

void	strlcat_tester(void)
{
	printf("Testing ft_strlcat against strlcat...\n");

	char dst1[20], dst2[20];
	char src[] = "World";

	strcpy(dst1, "Hello ");
	strcpy(dst2, "Hello ");

	//regular stuff
	size_t out1 = ft_strlcat(dst1, src, sizeof(dst1));
	size_t out2 = strlcat(dst2, src, sizeof(dst2));
	assert(out1 == out2 && strcmp(dst1, dst2) == 0);

	//n is too small: no concatenation
	strcpy(dst1, "Hello ");
	strcpy(dst2, "Hello ");

	out1 = ft_strlcat(dst1, src, 3);
	out2 = strlcat(dst2, src, 3);
	assert(out1 == out2 && strcmp(dst1, dst2) == 0);

	//concatenate to empty string
	dst1[0] = 0;
	dst2[0] = 0;
	out1 = ft_strlcat(dst1, src, sizeof(dst1));
	out2 = strlcat(dst2, src, sizeof(dst2));
	assert(out1 == out2 && strcmp(dst1, dst2) == 0);

	//src is empty
	strcpy(dst1, "Hello ");
	strcpy(dst2, "Hello ");
	out1 = ft_strlcat(dst1, "", sizeof(dst1));
	out2 = strlcat(dst2, "", sizeof(dst2));
	assert(out1 == out2 && strcmp(dst1, dst2) == 0);

	printf("You're strlcat works!\n");
}

void	strlcpy_tester(void)
{
	printf("Testing ft_strlcpy against strlcpy...\n");

	char dst1[20], dst2[20];
	char src[] = "Hello World";
	size_t out1 = ft_strlcpy(dst1, src, sizeof(dst1));
	size_t out2 = strlcpy(dst2, src, sizeof(dst2));
	assert(out1 == out2 && strcmp(dst1, dst2) == 0);

	//n less than src length
	out1 = ft_strlcpy(dst1, src, 5);
	out2 = strlcpy(dst2, src, 5);
	assert(out1 == out2 && strcmp(dst1, dst2) == 0);

	//n is 0
	out1 = ft_strlcpy(dst1, src, 0);
	out2 = strlcpy(dst2, src, 0);
	assert(out1 == out2);

	//src is empty
	out1 = ft_strlcpy(dst1, "", sizeof(dst1));
	out2 = strlcpy(dst2, "", sizeof(dst2));
	assert(out1 == out2 && strcmp(dst1, dst2) == 0);

	printf("You're strlcpy works!\n");
}

void	strlen_tester(void)
{
	printf("Testing ft_strlen against strlen...\n");

	char s1[] = "Hello World";
	assert(ft_strlen(s1) == strlen(s1));

	char s2[] = "";
	assert(ft_strlen(s2) == strlen(s2));

	char s3[] = "abc\0def";
	assert(ft_strlen(s3) == strlen(s3));

	char s4[] = "a";
	assert(ft_strlen(s4) == strlen(s4));

	printf("You're strlen works!\n");
}

void	strncmp_tester(void)
{
	printf("Testing ft_strncmp against strncmp...\n");

	char s1[] = "Hello World";
	char s2[] = "Hello World";
	assert(ft_strncmp(s1, s2, 20) == strncmp(s1, s2, 20));

	char s3[] = "Hello";
	char s4[] = "Hella";
	assert(ft_strncmp(s3, s4, 5) == strncmp(s3, s4, 5));

	//n less than difference
	assert(ft_strncmp(s3, s4, 2) == strncmp(s3, s4, 2));

	//n is 0
	assert(ft_strncmp(s3, s4, 0) == strncmp(s3, s4, 0));

	char s5[] = "";
	char s6[] = "Hello";
	assert(ft_strncmp(s5, s6, 2) == strncmp(s5, s6, 2));

	printf("You're strncmp works!\n");
}

void	strnstr_tester(void)
{
	printf("Testing ft_strnstr against strnstr...\n");

	char s1[] = "Hello World";

	char *out1 = ft_strnstr(s1, "World", 11);
	char *out2 = strnstr(s1, "World", 11);
	assert(out1 == out2);

	//needle not found
	out1 = ft_strnstr(s1, "Earth", 11);
	out2 = strnstr(s1, "Earth", 11);
	assert(out1 == out2);

	//empty needle
	out1 = ft_strnstr(s1, "", 11);
	out2 = strnstr(s1, "", 11);
	assert(out1 == out2);

	//n less than where needle appears
	out1 = ft_strnstr(s1, "World", 5);
	out2 = strnstr(s1, "World", 5);
	assert(out1 == out2);

	printf("You're strnstr works!\n");
}

void	strrchr_tester(void)
{
	printf("Testing ft_strrchr against strrchr...\n");

	char s1[] = "Hello World";
	char find = 'l';
	char *out1 = ft_strrchr(s1, find);
	char *out2 = strrchr(s1, find);
	assert(out1 == out2);

	//find not found
	find = 'x';
	out1 = ft_strrchr(s1, find);
	out2 = strrchr(s1, find);
	assert(out1 == out2);

	//find null terminator
	find = '\0';
	out1 = ft_strrchr(s1, find);
	out2 = strrchr(s1, find);
	assert(out1 == out2);

	//single char string
	char s2[] = "a";
	find = 'a';
	out1 = ft_strrchr(s2, find);
	out2 = strrchr(s2, find);
	assert(out1 == out2);

	printf("You're strrchr works!\n");
}

void	tolower_tester(void)
{
	printf("Testing ft_tolower against tolower...\n");
	for (int c = 0; c < 300; ++c)
		assert(ft_tolower(c) == tolower(c));
	printf("You're tolower works!\n");
}

void	toupper_tester(void)
{
	printf("Testing ft_toupper against toupper...\n");
	for (int c = 0; c < 300; ++c)
		assert(ft_toupper(c) == toupper(c));
	printf("You're toupper works!\n");
}
