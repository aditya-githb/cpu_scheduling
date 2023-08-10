#include<stdio.h>
#include<stdlib.h>
struct pcb{
int pid,at,bt,ct,tat,wt;
};  
int pline(int x){
for(int i=0;i<=x;i++){
printf("-");
}
printf("\n");
}
int main(){
struct pcb p[10],temp;
int num,t_waiting=0,t_turnAround=0,currentTime=0;
float a_wt=0,a_tat=0;
printf("Enter Number of Processes: ");
scanf("%d",&num);
for(int i=0;i<num;i++){
printf("\nEnter Arrival Time and Burst Time of Process %d: ",i+1);
scanf("%d%d",&p[i].at,&p[i].bt);
p[i].pid=i+1;
}
for(int i=0;i<num;i++){
for(int j=0;j<num-i-1;j++){
if(p[j].at>p[j+1].at){
temp=p[j+1];
p[j+1]=p[j];
p[j]=temp;
}
}
}
p[0].wt=0;
p[0].ct=p[0].bt+p[0].at;
p[0].tat=p[0].ct-p[0].at;
currentTime=p[0].ct;
for(int i=1;i<num;i++){
if(p[i].at>=currentTime){
currentTime=p[i].at;
p[i].wt=0;
p[i].ct=currentTime+p[i].bt;
p[i].tat=p[i].ct-p[i].at;
currentTime=p[i].ct;
}else{
p[i].ct=p[i-1].ct+p[i].bt;
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
currentTime=p[i].ct;
}
}
pline(64);
printf("\npid\tarrival\tburst\tcompletion Time\tTurnaroundTime\tWaitingTime\n");
pline(64);
for(int i=0;i<num;i++){
printf("\n%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
t_turnAround+=p[i].tat;
t_waiting+=p[i].wt;
}
pline(64);
a_wt=(float)t_waiting/(float)num;
a_tat=(float)t_turnAround/(float)num;
printf("\nTotal Waiting Time: %d\nAverage Waiting Time: %.2f\n",t_waiting,a_wt);
printf("\nTotal TurnAround Time: %d\nAverage TurnAround Time: %.2f\n",t_turnAround,a_tat);
return 0;
}
