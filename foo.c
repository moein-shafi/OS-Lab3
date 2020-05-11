#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define NUMBER_OF_PROCESSES 10
#define ONE 1

int main(int argc, char const *argv[])
{
	int pid = getpid();
	int i;

	for (i = ONE; i < NUMBER_OF_PROCESSES; ++i)
	{
		if (pid > 0)
		{
			switch(i)
			{
				case 2:
					set_proc_queue(pid, 1);
					set_proc_ticket(pid, 16);
					break;

				case 4:
					set_proc_queue(pid, 2);
					break;

				case 6:
					set_proc_queue(pid, 2);
					break;

				case 8:
					set_proc_queue(pid, 1);
					set_proc_ticket(pid, 40);
					break;
			}
			pid = fork();
		}
	}

	if(pid < 0)
    {
        printf(2, "fork failed!\n");
    }
	else if (pid == 0)
	{
        int z = 1;
        for(int j = 0; j < 10000000.0; j+=1)
            z += (j + 1);
		printf (2, "", z);
		printf(2, "process with pid %d is finished!\n", i);
	}
	else
	{
		for (i = 0; i < NUMBER_OF_PROCESSES; i++)
			wait();
		printf(1, "Scheduling test is finished!\n");
	}

	exit();
	return 0;
}