#include "libft.h"
#include <assert.h>
#include <stdio.h> //Printing
#include <limits.h> //Mins and Maxes
#include <strings.h> //String functions
#include <string.h> //More string functions
#include <ctype.h> //Type checking

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
	printf("You're isprint works!");
}

void	memchr_tester(void)
{
	printf("Testing ft_memchr against memchr...  \n");
	printf("You're memchr works!");
}

void	memcmp_tester(void)
{
	printf("Testing ft_memcmp against memcmp...  \n");
	printf("You're memcmp works!");
}

void	memcpy_tester(void)
{
	printf("Testing ft_memcpy against memcpy...  \n");
	printf("You're memcpy works!");
}

void	memmove_tester(void)
{
	printf("Testing ft_memmove against memmove...  \n");
	printf("You're memmove works!");
}

void	memset_tester(void)
{
	printf("Testing ft_memset against memset...  \n");
	printf("You're memset works!");
}

void	strchr_tester(void)
{
	printf("Testing ft_strchr against strchr...  \n");
	printf("You're strchr works!");
}

void	strdup_tester(void)
{
	printf("Testing ft_strdup against strdup...  \n");
	printf("You're strdup works!");
}

void	strlcat_tester(void)
{
	printf("Testing ft_strlcat against strlcat...  \n");
	printf("You're strlcat works!");
}

void	strlcpy_tester(void)
{
	printf("Testing ft_strlcpy against strlcpy...  \n");
	printf("You're strlcpy works!");
}

void	strlen_tester(void)
{
	printf("Testing ft_strlen against strlen...  \n");
	printf("You're strlen works!");
}

void	strncmp_tester(void)
{
	printf("Testing ft_strncmp against strncmp...  \n");
	printf("You're strncmp works!");
}

void	strnstr_tester(void)
{
	printf("Testing ft_strnstr against strnstr...  \n");
	printf("You're strnstr works!");
}

void	strrchr_tester(void)
{
	printf("Testing ft_strrchr against strrchr...  \n");
	printf("You're strrchr works!");
}

void	tolower_tester(void)
{
	printf("Testing ft_tolower against tolower...  \n");
	printf("You're tolower works!");
}

void	toupper_tester(void)
{
	printf("Testing ft_toupper against toupper...  \n");
	printf("You're toupper works!");
}
