// Including the unistd header for the write(2) function
#include <unistd.h>
// Including the fcntl header for the open(2) function
#include <fcntl.h>

// Prototypes of the functions declared under the main function
void ft_putchar_terminal(char c);
void ft_putchar_test_file(char c);

// main function
int main(void)
{
    // calling the ft_putchar_terminal function with character T
    ft_putchar_terminal('T');
    // calling the ft_putchar_test_file function with character F
    ft_putchar_test_file('F');
    return (0);
}

/* This function will simply write one character to the terminal on the 
 * standard output. As explained above, the fd for stdout is 1, so we put
 * 1 as a first parameter to the write(2) function.
 */
void ft_putchar_terminal(char c)
{
    write(1, &c, 1);
}

/* This function will open a file called "test.txt" with the open(2) function.
 * Once the file is opened, store the file descriptor in the fd variable.
 * I then check if there was an error opening the file.
 * If no error, I write the character F in the file test.txt
 * If there is an error, I write an error message to the standard error output.
 */
void ft_putchar_test_file(char c)
{
    int fd;
    
    /* Opening the test.txt file in Read/Write mode with open(2) function
     * then assigning the returned file descriptor value to the fd variable.
     */
    fd = open("test.txt", O_RDWR);
    /* Checking if the file was correctly opened.
     * The open function returns -1 if there is an error opening the file.
     */
    if (fd > 0)
        /* Writing the F character to the test.txt file by passing
         * its file descriptor as first parameter to the write(2) function.
         */
        write(fd, &c, 1);
    else
        /* If there was an error opening the file, the value of fd will be -1
         * thus it won't go inside the previous condition so I write an error
         * message to the stderr by passing the fd descriptor 2 as first parameter
         * to the write(2) function.
         */
        write(2, "test.txt not found.\n", 20);
}