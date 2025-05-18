#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	//testing happens from A to Z
	int i = atoi_tester();
	if (i != 0)
		printf("Tester did not pass.");
	return (0);
}

int	atoi_tester(void)
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

	//Large numbers
	assert(ft_atoi("999999999999999999999999") == atoi("999999999999999999999999"));

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

	printf("Everything passed!");
	return (0);
}
