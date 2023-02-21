#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;

void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specifictrain(int);
float charge(int,int);
void menu(void);
int main()
{
	int menu_choice,choice_return;
	clrscr();
	printf("\t\t===============================================\n");
	printf("\t\t                                               \n");
	printf("\t\t        -----------------------------          \n");
	printf("\t\t         Railway Reservation System            \n");
	printf("\t\t        -----------------------------          \n");
	printf("\t\t                                               \n");
	printf("\t\t                                               \n");
	printf("\t\t         Presented by:-                        \n");
	printf("\t\t              Parth Tagadpallewar              \n");
	printf("\t\t              Rohit Rathod                     \n");
	printf("\t\t                                               \n");
	printf("\t\t===============================================\n\n\n");
	printf(" \n Press any key to continue:");
	getch();
	clrscr();
	start:
	clrscr();
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1 Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2 View All Available Trains");
	printf("\n------------------------");
	printf("\n3 Exit");
	printf("\n------------------------");
	printf("\n\nEnter the option:");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
			goto start;
	}
	return(0);
}

void viewdetails(void)
{
clrscr();
printf("-----------------------------------------------------------------------------");
printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
printf("-----------------------------------------------------------------------------");
printf("\n1000\tKolhapur Express  \tPurna to Kolhapur  \tRs.5000\t\t6am");
printf("\n1001\tDevgiri Express   \tNanded to Pune     \tRs.5000\t\t9am");
printf("\n1002\tChennai Express   \tMumbai to Chennai  \tRs.5000\t\t12pm");
printf("\n1003\tPune City Express \tNanded to Pune     \tRs.4500\t\t8am");
printf("\n1004\tNandigram Express \tNanded to Mumbai   \tRs.4500\t\t11am");
printf("\n1005\tHigh Court        \tManmad to Nanded   \tRs.4000\t\t7am");
printf("\n1006\tSach khand Express\tNanded to Amrutsar \tRs.4000\t\t9.30am");
printf("\n1007\tPanvel Express        \tNanded to Panvel   \tRs.3500\t\t1pm");
printf("\n1008\tHaidrabad Express     \tNanded to Haidrabad\tRs.3500\t\t4pm");
printf("\n1009\tNagarsol Express      \tNanded to Miami    \tRs.6000\t\t3.35pm");
printf("\n1010\tLokmanya Tilak Express\tMumbai to Kolkatta \tRs.6000\t\t4.15pm");
}
void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	clrscr();
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1000 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}
float charge(int train_num,int num_of_seats)
{
	if (train_num==1000)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1001)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(6000.0*num_of_seats);
	}
}
void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	clrscr();
	printf("    -------------------\n");
	printf("\t       TICKET\n");
	printf("    -------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}
void specifictrain(int train_num)
{

	if (train_num==1000)
	{
		printf("\nTrain:\t\t\tKolhapur Express");
		printf("\nDestination:\t\tPurna to Kolhapur");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tDevgiri Express");
		printf("\nDestination:\t\tNanded to Pune");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tChennai Express");
		printf("\nDestination:\t\tMumbai to Chennai");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tPune City Express ");
		printf("\nDestination:\t\tNanded to Pune     ");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tNandigram Express");
		printf("\nDestination:\t\tNanded to Mumbai   ");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==1005)
	{
		printf("\ntrain:\t\t\tHigh Court ");
		printf("\nDestination:\t\tManmad to Nanded   ");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tSach khand Express");
		printf("\nDestination:\t\tNanded to Amrutsar ");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tPanvel Express");
		printf("\n Destination:\t\tNanded to Panvel");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tHaidrabad Express ");
		printf("\nDestination:\t\tNanded to Haidrabad");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tNagarsol Express");
		printf("\nDestination:\t\tNanded to Miami    ");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tLokmanya Tilak Express");
		printf("\nDestination:\t\tMumbai to Kolkatta ");
		printf("\nDeparture:\t\t1.15 ");
	}
}
