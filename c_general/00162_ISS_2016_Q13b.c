#include<stdio.h>

int main()
{
	int n_tender;

	printf("Enter the number of tenders = ");
	scanf("%d", &n_tender);

	int information[n_tender][2];

	for(int i = 0; i < n_tender; i++){
		printf("Enter tender id[%d] = ", i+1);
		scanf("%d", &information[i][0]);

		printf("Enter tender-value = ");
		scanf("%d", &information[i][1]);
	}

	printf("All tender information is displayed below\n");

	for(int i = 0; i < n_tender; i++){
		printf("Tender-id :: %d \t Tender-value :: %d\n", information[i][0], information[i][1]);
	}
	
	int largest_tender_value_index = 0;

	for(int i = 0; i < n_tender - 1; i++){
		if(information[i+1][1] > information[largest_tender_value_index][1]){
			largest_tender_value_index = i + 1;
		}
	}

	printf("Largest Tender-id is %d with Tender-value = %d\n", information[largest_tender_value_index][0], information[largest_tender_value_index][1]);

	return 0;
}
