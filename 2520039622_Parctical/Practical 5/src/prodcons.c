#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>//for wair syscall
#include<time.h>//for clocks_per_sec and clock() syscall
int main()
{
int fd[2];//parameter for anonymus pipes
int data;//varaiable that writes data to pipe
int start,end;//variables that take start and end times
double timetaken,communication_efficiency;//varaibale that calcualtes communication time
pipe(fd);//creating a anonymus pipes
start=clock();//storing start time
if(fork()==0)//creating a child as consumer
{
close(fd[1]);//closing the write end of the pipe
printf("Consumer \n");//starting the consumer
for(int i=0;i<5;i++)
{
read(fd[0],&data,sizeof(data));
printf("Consumed %d \n",data);
}
close(fd[0]);
}
else
{
close(fd[0]);//closing the read end of the pipe in parent
printf("Producer \n");//initializing the data values in the producer
for(int i = 1;i<=5;i++)//defining the producer data
{
data = i*10;//initializing the data values in the producer
write(fd[1],&data,sizeof(data));//writing data into the pipe
printf("Produced %d\n",data);//printing the produced data
}
close(fd[1]);//closing the write end of the pipe
wait(NULL);//parent waits for the child to complete
end=clock();//closing the clock to take the communication time
timetaken=(double)(end-start)/CLOCKS_PER_SEC;//calculating the time taken
printf("Communication  time is %lf\n",timetaken);//printing time taken
communication_efficiency = 5/timetaken;
printf("Communication time is %lf\n",communication_efficiency);
}
}