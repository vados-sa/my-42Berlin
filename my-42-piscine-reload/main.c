//ft_isalpha
/* 
int	main(void)
{
	char	c;

	c = 'a';
	printf("%d\n", isalpha(c));
	printf("%d\n", ft_isalpha(c));
	return (0); 
} */

//ft_isdigit
/* 
int	main(void)
{
	char	c;

	c = '5';
	printf("%d\n", isdigit(c));
	printf("%d\n", ft_isdigit(c));
	return (0); 
} */

//ft_isalnum
/* int	main(void)
{
	char	c;

	c = '5';
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));
	return (0); 
} */

//ft_isascii
/* 
int	main(void)
{
	char	c;

	c = 'ç';
	printf("function: %d.\nimplementation: %d.\n", isascii(c), ft_isascii(c));
} */

//ft_isprint
/* int	main(void)
{
	char	c;

	c = ' ';
	printf("function: %d.\nimplementation: %d.\n", isprint(c), ft_isprint(c));
	return (0);
} */

//ft_strlen
/* 
int	main(void)
{
	char str[] = "Vanessa";
	printf("funtion: %lu.\nimplem.: %d.\n", strlen(str), ft_strlen(str));
	return (0);
} */

//ft_memset
/* int main() 
{
	size_t	size = 2;
	char 	c = 'V';
	char 	str[20];
	printf("Funtion: %s\n", (char*)memset(str, c, size));
	str[10] = '\0';
	printf("Implementation: %s\n", (char*)ft_memset(str, c, size));
	return 0;
} */

//ft_bzero
/* 
int	main(void)
{
	char str1[] = "chocolate";
	ft_bzero(str1, 0);
	printf ("%s\n", str1);
	char str[] = "chocolate";
	ft_bzero(str, 0);
	printf ("%s\n", str);
} */

//ft_memcpy
/* 
int main(void) {
	char source[] = "Copykitty";
	char destination[10];
	char dest[10];

	printf("Destination: %s\n", (char *)memcpy(destination, source + 2, 7));
	printf("Dest.:       %s\n", (char *)ft_memcpy(dest, source + 2, 7));
	//null terminate in the main?
	return 0;
} */

//ft_memmove
/* 
int	main(void)
{
	char source[] = "Copycat";
	char	destination[7];
	char	dest[7];

	printf("Original Source: %s\n", source);

	memmove(destination, source + 2, 4);
	printf("Destination (memmove): %s\n", destination);

	ft_memmove(dest, source + 2, 4);
	printf("Dest. (ft_memmove): %s\n", dest);

	return (0);
} */

//ft_strlcpy
/* int	main(void)
{
	char	src[] = "aaa";
	char	dest[3];
	printf("len of copied str: %zu.\ncopied str: %s\n", ft_strlcpy(dest, src, sizeof(dest)), dest);
	return (0);
} */

//ft_strlcat
/* 
int	main(void)
{
	char	src[] = " S";
	char	dest[15] = "Vanessa";
	printf ("Size of concatenated str: %zu.\n", ft_strlcat(dest, src, sizeof(dest)));
	printf ("Concatenated string: %s.\n", ft_strlcat(dest, src, sizeof(dest)));
	return (0);
} */

//ft_toupper
/* 
int	main(void)
{
	char	c;

	c = 'C';
	printf("funtion: %c.\nindent.: %c.\n", toupper(c), ft_toupper(c));
	return (0);
}
*/

//ft_tolower
/* 
int	main(void)
{
	char	c;

	c = '9';
	printf("funtion: %c.\nindent.: %c.\n", tolower(c), ft_tolower(c));
	return (0);
} */

//ft_strchr
/* int	main(void)
{
	char	str[] = "sabao cracra";
	char	c = 'c';
	printf("%s\n", ft_strchr(str, c));
	return (0);
} */

//ft_strrchr
/* 
int	main(void)
{
	char	str[] = "sabao cracra";
	char	c = 'c';
	printf("%s\n", ft_strrchr(str, c));
	return (0);
} */

//ft_strncmp
/* 
int	main(void)
{
	char s1[] = "hello";
	char s2[] = "he";
	unsigned int n = 4;
	printf("funtion: %d\nimplement.: %d\n", strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	return (0);
} */

//ft_memchr
/* int	main(void)
{
	char str[] = "abacate";
	void *result = ft_memchr(str, 'p', 7);
	if (result != NULL)
		printf ("%c\n", *((char *)result));
	//The cast (char *)result is used to treat the result
	//as a pointer to a character, 
	//and *((char *)result) dereferences the pointer
	//to get the actual character.
	//else
        printf("Character not found.\n");
	return (0);
} */

//ft_memcmp
/* 
int	main(void)
{
	char str1[] = "a";
	char str2[] = " ";
	printf("%d\n", ft_memcmp(str1, str2, 4));
	return (0);
} */

//ft_strnstr
/* 
int	main(void)
{
	char haystack[] = "Testing with an empty needle";
	char needle[] = "";
	size_t len = 28;

	printf ("%s.\n", ft_strnstr(haystack, needle, len));
	return (0);
} */

//ft_atoi
/* 
int	main(void)
{
	char str[] = "      +1254845538";
	printf("atoi: %d\nft_atoi: %d\n", atoi(str), ft_atoi(str));
	return (0);
} */

//ft_calloc
/* 
int	main(void)
{
	size_t nitems = 5;
    size_t size = sizeof(int);
	ft_calloc(nitems, size);
	free (ft_calloc(nitems, size));
	return (0);
} */

//ft_strdup
/* 
int	main(void)
{
	char src[] = "hi there potato";
	printf("%s | %s\n", src, strdup(src));
	printf("%s", ft_strdup(src));
	free(ft_strdup(src));	
	return (0);		
} */
//ft_substr
/* 
int	main(void)
{
	const char	str[] = "abcdefghijklmnopqrstuvwxyz";
	unsigned int	start = 5;
	size_t	len = 26;
	char *result = ft_substr(str, start, len);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return (0);
} */

//ft_strjoin
/* int main(void)
{
	char str1[] = "Vanessa ";
	char str2[] = "Santos";
	char *result = ft_strjoin(str1, str2);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return (0);
} */

//ft_strtrim
/* 
int main(void)
{
	char s1[] = "\t\t This\nis\ta\ntest \t\t\n\n";
	char set[] = "\t\n";
	char *result = ft_strtrim(s1, set);
	if (result)
	{
		printf("%s", result);
		free(result);
	}
	return (0);
} */

//ft_split
/* int	main(void)
{
	int	i;
	char	str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	char 	c = ' ';
	
	char **result = ft_split(str, c);
	i = 0;
	while (result[i])
	{
		printf("Substring %d: %s\n", i, result[i]);
		i++;
	}
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
} */

//ft_itoa
/* 
int	main(void)
{
	int	n;
	
	n = 2147483647;
	char *result;
	result = ft_itoa(n);
	printf ("%s\n", result);
	free (result);
	return (0);
} */

//ft_strmapi

//ft_striteri

//ft_putchar_fd
/* #include <fcntl.h>
int	main()
{
	char letter = 'A';

    // Write to standard output (stdout)
    ft_putchar_fd(letter, 1);

    // Write to standard error (stderr)
    ft_putchar_fd(letter, 2);

    // Write to a file (replace "output.txt" with the desired file name)
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }
    ft_putchar_fd(letter, file_descriptor);

    // Close the file descriptor
    close(file_descriptor);

	return (0);
} */

//ft_putstr_fd
/* #include <fcntl.h>
int main()
{
    char *message = "Hello, World!\n";

    // Write to standard output (stdout)
    ft_putstr_fd(message, 1);

    // Write to standard error (stderr)
    ft_putstr_fd(message, 2);

    // Write to a file (replace "output.txt" with the desired file name)
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }
    ft_putstr_fd(message, file_descriptor);

    // Close the file descriptor
    close(file_descriptor);

    return 0;
} */

//ft_putendl_fd
/* #include <fcntl.h>
int main()
{
    char *message = "Hello, World!";

    // Write to standard output (stdout)
    ft_putendl_fd(message, 1);

    // Write to standard error (stderr)
    ft_putendl_fd(message, 2);

    // Write to a file (replace "output.txt" with the desired file name)
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }
    ft_putendl_fd(message, file_descriptor);

    // Close the file descriptor
    close(file_descriptor);

    return 0;
} */

//ft_putnbr_fd
/* int main(void)
{
    int number1 = 123;
    int number2 = -456;
    int number3 = 0;

    // Test with positive number
    ft_putnbr_fd(number1, 1); // Assuming 1 is the file descriptor for standard output
    ft_putchar_fd('\n', 1);

    // Test with negative number
    ft_putnbr_fd(number2, 1);
    ft_putchar_fd('\n', 1);

    // Test with zero
    ft_putnbr_fd(number3, 1);
    ft_putchar_fd('\n', 1);

    return 0;
} */
