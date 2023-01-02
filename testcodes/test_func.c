# include <dirent.h>
# include <stdio.h>
# include <unistd.h>

int	main(int ac, char **av)
{
	DIR*	dir;
	char	*str;
	char	*pwd_a;

	struct dirent* entry;
	pwd_a = getcwd(0, 0);

	printf("%s\n", pwd_a);


	printf("----\n");

	if (!chdir(av[1]))
		printf("Success change\n");
	else
		printf("Fail change\n");
	
	printf("----\n");
	

	pwd_a = getcwd(0, 0);
	printf("%s\n", pwd_a);

	// else
	// 	puts("success to open");
	
	// while ((entry = readdir(dir)) != NULL)
	// 	puts("success to open");

}

// #include <signal.h>
// #include <stdio.h>

// void handle_sigint(int sig)
// {
//     printf("Caught signal %d\n", sig);
// }

// int main(void)
// {
//     Set up the signal handler for SIGINT (Ctrl+C)
//     signal(SIGINT, handle_sigint);

//     Do some work
//     while (1) {
//         printf("Working...\n");
//         sleep(1);
//     }

//     return 0;
// }