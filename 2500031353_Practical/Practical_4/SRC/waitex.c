 #include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>//used for wair() and waitpid() systemcalls
#include<stdlib.h>//used for exit() systemcall
int main()
{
int pid[3];//initializing 3 childs
for(int i=0;i<3;i++)//loop which runs for 3 childs
{
pid[i]=fork();//creating 3 childs
if(pid[i]==0)//indicates a child process
{
printf("Child %d pid=%d\n",i+1,getpid());
sleep(i+1);//giving a pause after every child
exit(0);//exiting the standard input
}
}
wait(NULL);//waiting for any one child
printf("Parent:One child is completed with wait()\n");//parent is returning the
waitpid(pid[2],NULL,0);//waiting using a specific pid
printf("Parent:Child 3 has completed with waitid()\n");
wait(NULL);//waiting for last child to execute.
printf("Parent:All the childs are completed\n");
} 
