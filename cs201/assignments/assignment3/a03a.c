// Numbers from command line arguments are sent to child process
// from parent process one at a time through pipe.
//
// Child process adds up numbers sent through pipe.
//
// Child process returns sum of numbers to parent process.
//
// Parent process prints sum of numbers.

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	// set up pipe A and pipe 
	int pA[2];
	int pB[2];

	pipe(pA);
	pipe(pB);
	
	// call fork()
	pid_t childId = fork();

	if (childId == 0) {
		
		// -- running in child process --
		int avg = 0, num = 0, nCount = 0;
		
		//close the input of pA
		close(pA[1]);

		// Receive characters from parent process via pipe
		// one at a time, counting them and adding them together
		while(read(pA[0], &num, sizeof(int)) && num != 0)
		{
			avg = avg + num;
			nCount++;
		}
		close(pA[0]); // close output of pipe A

		if(nCount % 2 == 0) //Determine if the number of intergers is even or not
		{
			avg = avg/nCount; //Calculate average of series of numbers
			close(pB[0]); //Close output of pipe B
			write(pB[1], &avg, sizeof(int));
			close(pB[1]); //Close input of pipe B
		}
		else
		{
			avg = 0; //Average of odd number of integers
			close(pB[0]);
			write(pB[1], &avg, sizeof(int));
			close(pB[1]);
			return avg;
		}
	}
	else {
		// -- running in parent process --
		int avg = 0;

		// Send numbers
		// starting with argv[1] one at a time through pipe to child process.
		
		close(pA[0]); // Close output of pipe A
		
		printf("CS201 - Assignment 3 Regular - Adam La Fleur\n"); 
		for(int i = 1; i < argc; i++)
		{
			int num = atoi(argv[i]);
			write(pA[1], &num, sizeof(int));
		}
		close(pA[1]); //Close input of pipe A

		// Wait for child process to return. Reap child process.
		
		wait(&avg);
		//wait(NULL);
		printf("%d\n", avg);
		// Receive sum of numbers via the value returned when
		// the child process is reaped.
		close(pB[1]);
		read(pB[0], &avg, sizeof(int));
		close(pB[0]);
		if(avg != 0)
		{
			printf("avg = %d\n", avg);
		}
		else
		{
			printf("Error in the data\n");
		}
		return 0;
		}
}
