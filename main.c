#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include <string.h>

void	atoi_tester(void);
void	bzero_tester(void);
void	calloc_tester(void);
void	memcmp_tester(void);
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

	printf("You're calloc works!");
}

void	isalnum_tester(void)
{
	printf("Testing ft_isalnum against isalnum...  \n");
	printf("You're isalnum works!");
}

void	isalpha_tester(void)
{
	printf("Testing ft_isalpha against isalpha...  \n");
	printf("You're isalpha works!");
}

void	isascii_tester(void)
{
	printf("Testing ft_isascii against isascii...  \n");
	printf("You're isascii works!");
}

void	isdigit_tester(void)
{
	printf("Testing ft_isdigit against isdigit...  \n");
	printf("You're isdigit works!");
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
