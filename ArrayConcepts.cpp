//write a menu based program in c to traversal/ display an array, 
//insert an item to any location, delete an item from any location, 
//search an item in an arrau using linear search and sort the arry 
//using bubble sort


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//display/traversal array function;
int displayArray(int arr[], int used_size){
	printf("Printing Array elements....\n");
	for(int i = 0; i < used_size ; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}
//insertion to array
int insertion(int arr[],int used_size, int index, int element){
	if(used_size>=100){
		printf("Insertion unsuccesful");
		return -1;
	}
	else{
		for(int i = used_size; i > index ; i--){
		arr[i] = arr[i-1];
	    }
	    arr[index] = element;
		printf("Insertion is succesful");
	}
	return 0;
}
//Deleting an element from array
int deletetion(int arr[],int used_size, int delIndex){
	if(delIndex>=used_size){
		printf("Enter valid index\n");
		return -1;
	}
	for(int i = delIndex ; i < used_size ; i++){
		arr[i-1] = arr[i];
	}
	return 0;
}
// sorting the array in acs/des
int bubbleSort(int arr[], int used_size, int choose){
	printf("Operating Bubble sort to array....\n");
	int temp;
	if(choose == 1){
		for(int i = 0; i < (used_size-1); i++){
		    for(int j = 0; j < (used_size-1-i); j++){
			    if(arr[j]>arr[j+1]){
				    temp = arr[j];
				    arr[j] = arr[j+1];
				    arr[j+1] = temp;
			   }
	        }
	    }
	    printf("Sorting done in ascending order...\n");
	    
	}
	else{
	    	for(int i = 0; i < (used_size-1); i++){
		        for(int j = 0; j < (used_size-1-i); j++){
			        if(arr[j]<arr[j+1]){
				        temp = arr[j];
				        arr[j] = arr[j+1];
				        arr[j+1] = temp;
			        }
	            }
	        }
	        printf("Sorting done in descending order...\n");
	    }
	
	return 0;
}
// Searching using Linear Search
int linearSearch(int arr[], int used_size, int find){
	for(int i = 0; i < used_size; i++){
		if(arr[i]==find){
			return i;
		}
	}
	return -1;
}
int main(){
	system("Color F2");
	int total_size = 100;
	int used_size = 7;
	int arr[] = {23,55,43,20,14,3,54};
	int choice = NULL;
	do{
		printf("\n-------------------------------------------\n");
		printf("| Enter 1 to display array elements       |\n");
		printf("| Enter 2 to insert an element from array |\n");
		printf("| Enter 3 to delete an element from array |\n");
		printf("| Enter 4 to search an element from array |\n");
		printf("| Enter 5 to sort array elements          |\n");
		printf("| Enter 6 to exit from program            |");
		printf("\n-------------------------------------------\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				displayArray(arr , used_size);
				break;
			case 2:
			    int index , element;
				printf("Insertion an element\n");
				printf("Enter to location where you want to insert\n");
				scanf("%d",&index);
				printf("Enter the element which you want to insert\n");
				scanf("%d",&element);
				insertion(arr, used_size, index, element);
				used_size = used_size + 1;	
				break;
			case 3:
				int delIndex, check;
				printf("Delete element from the array...\n");
				printf("Enter the index from where you want delete element.\n");
				scanf("%d",&delIndex);
				check = deletetion(arr, used_size, delIndex);
				if(check == -1){
					printf("Deletion is unsuccesful..\n");
				}
				else{
					printf("Element deletion is succesful.\n");
				}
				
				used_size = used_size - 1;
			    break;
			case 4:
				int find , locationFound;
				printf("Searching an element in array...\n");
				printf("Enter the element you want to find : \n");
				scanf("%d",&find);
				locationFound = linearSearch(arr,used_size,find);
				if(locationFound == -1){
					printf("Unable to find array element..\n");
				}
				else{
					printf("Element found at index %d and the element was %d\n",locationFound,find);
				}
			    break;
			case 5:
				int choose;
				printf("Want to sort the array..\n");
				printf("Enter 1 to sort in Accending order.\n");
				printf("Enter 2 to sort in Decending order.\n");
				scanf("%d",&choose);
				if(choose == 1 || choose == 2){
					if(choose==1){
						bubbleSort(arr, used_size, choose);
					}
					else{
						bubbleSort(arr, used_size, choose);
					}
				}
				else{
					printf("Enter valid choice..\n");
				}
			    break;			
			case 6:
			    exit(0);
				break;
			default:
			    printf("Enter valid choice");
				break;		
				
		}
	}while(choice!=6);
	return 0;
}

