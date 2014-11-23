#include <stdio.h>
#include <stdlib.h>

typedef struct proc{
	int val;
	int wait;
	int turn_at;
} proc;

void RoundRobin()
{
	int no, i, qt, check;
	int time = 0, tmp, tat_s = 0, wt_s = 0;
	proc *list;
	
	printf("Enter the no of processes\n");
	scanf("%d", &no);
	list = malloc(sizeof(proc) * no);
	printf("Enter the burst time of each\n");
	for (i = 0; i < no; i++) {
		scanf("%d", &list[i].val);
		list[i].wait = list[i].val;
	}
	printf("Enter the quatum time\n");
	scanf("%d", &qt);
	check = no;
	while (check) {
		for (i = 0; i < no; i++) {
			if (!list[i].val) {
				continue;
			}
			tmp = list[i].val > qt ? qt : list[i].val;
			list[i].val -= tmp;
			time += tmp;
			if (!list[i].val) {
				list[i].turn_at = time;
				list[i].wait = time - list[i].wait;
				check--;
			}
		}
	}
	printf("tat and wt times are :\n");
	for (i = 0; i < no; i++) {
		printf("tat : %d, wt : %d \n", list[i].turn_at, list[i].wait);
		tat_s += list[i].turn_at;
		wt_s += list[i].wait;
	}
	printf("Avg tat : %f\n", (float)tat_s/no);
	printf("Avg wt : %f\n", (float)wt_s/no);
	free(list);
}

typedef struct proc_b
{
	int val;
	int at;
	int ft;
	int bt;
	int wt;
	int tat;
} proc_b;

void ShortestJobFirst()
{
	int no, i, check, time, tmp, sum_wt, sum_tat;
	proc_b *list;
	
	printf("Enter no of processes\n");
	scanf("%d", &no);
	list = malloc(sizeof(proc_b) * no);
	printf("Enter the arrival time and value of each process\n");
	for (i = 0; i < no; i++) {
		scanf("%d %d", &list[i].at, &list[i].val);
		list[i].bt = list[i].val;
	}
	check = no;
	time = 0;
	while (check) {
		tmp = -1;
		for (i = 0; i < no; i++) {
			if (list[i].val) {
				if (tmp == -1 && list[i].at <= time)
					tmp = i;
				if (list[i].at <= time && list[i].val < list[tmp].val)
					tmp = i;
			}
		}
		list[tmp].val--;
		time++;
		if (!list[tmp].val) {
			list[tmp].ft = time;
			list[tmp].tat = time - list[tmp].at;
			list[tmp].wt = list[tmp].tat - list[tmp].bt;
			check--;
		}
	}
	sum_wt = 0;
	sum_tat = 0;
	for (i = 0; i < no; i++) {
		printf("P%d ft:%d\twt:%d\ttat:%d\n", i, list[i].ft, list[i].wt, list[i].tat);
		sum_wt += list[i].wt;
		sum_tat += list[i].tat;
	}
	printf("Avg tat : %f\n", (float)sum_wt/no);
	printf("Avg wt : %f\n", (float)sum_tat/no);
	free(list);
}
	

int main(int argc, char *argv[])
{
	int choice;
	
	printf("Enter your choice :\n");
	printf("1. RoundRobin\n");
	printf("2. ShortestJobFirst\n");
	scanf("%d", &choice);
	switch(choice) {
	case 1:
		RoundRobin();
		break;
	case 2:
		ShortestJobFirst();
		break;
	default:
		printf("Exit.\n");
		return 0;
	}
	return 0;
}
