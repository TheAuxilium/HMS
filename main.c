#include <stdio.h> //For standard IO operation
#include <stdlib.h> //For exit()
#include <windows.h>
#include <string.h>

struct patient{

	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char Problem[20];
};

struct patient p;

void gotoxy(int x, int y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void WelcomeScreen(void){

    printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\tWELCOME TO\t\t#");
	printf("\n\t\t\t\t# VP & KT HEALTHCARE MANAGEMENT SYSTEM  #");
	printf("\n\t\t\t\t#########################################");
	printf("\n\n\n\n\n \t \t\t\tPress any key to continue......");
	getch();
	system("cls");

}

void Title(void){

    printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t \t\t     VP&KT HOSPITAL         ");
	printf("\n\t\t----------------------------------------------------------------------------------");

}

void LoginScreen(void){

    int attempt=0;
    char Username[30];
    char Password[20];
    char admin_username[30]="admin";
    char admin_password[20]="admin";

    do{
        printf("\n\n\n\n\t\t\t\t\tEnter your Username and Password : ");
        printf("\n\n\n\t\t\t\t\tUSERNAME:");
        scanf("%s",&Username);

        printf("\n\n\t\t\t\t\tPASSWORD:");
        scanf("%s",&Password);

        if (strcmp(Username,admin_username)==0 && strcmp(Password,admin_password)==0){

            printf("\n\n\n\t\t\t\t\t...Login Successfull...");
            getch();
            MainMenu();
            break;
        }

        else
        {
            printf("\n\t\t\t\t\tPassword is incorrect. Try Again.");
            attempt++;
            getch();
        }

        }while(attempt<=2);

        if(attempt>2){

            printf("\n\n\n\n\t\t\t\t\tPlease try again later...\n\n");
            getch();
            exit(1);
        }

    system("cls");
}

void MainMenu(void){

    system("cls");
    Title();
    int option;
    printf("\n\n\n\n\n\t\t\t\t1.View Patients List \n");
    printf("\n\t\t\t\t2.Add Patient \n");
    printf("\n\t\t\t\t3.Delete Patient \n");
    printf("\n\t\t\t\t4.Exit \n");
    printf("\n\n\n\t\t\t\tYour choice: ");
    scanf("%d", &option);

    switch(option)
	{

	case 1:
        list();
    	break;

    case 2:
        Add();
        break;

    case 3:
        dlt();
        break;

	case 4:
		ext();
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();
	}
}

void Add(void){

	char ans;
	int b, valid=0, ok;

	system("cls");
	Title();

	FILE*ek;
	ek=fopen("Record2.dat","a");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");

    A:
        printf("\n\t\t\tFirst Name: ");
        scanf("%s",p.First_Name);
        p.First_Name[0]=toupper(p.First_Name[0]);
        if(strlen(p.First_Name)>20||strlen(p.First_Name)<2){

            printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
            goto A;
        }
        else{

            for(b=0;b<strlen(p.First_Name);b++){

                if (isalpha(p.First_Name[b])){

                    valid=1;
                }

                else{

                    valid=0;
                    break;
                }
            }

            if(!valid){

                printf("\n\t\t First name contain Invalid character :(  Enter again :)");
                goto A;
            }
        }

	B:
        printf("\n\t\t\tLast Name: ");
        scanf("%s",p.Last_Name);
        p.Last_Name[0]=toupper(p.Last_Name[0]);
        if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2){

            printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
            goto B;
        }

        else{

            for (b=0;b<strlen(p.Last_Name);b++){

                if (isalpha(p.Last_Name[b])){

                    valid=1;
                }
                else{

                    valid=0;
                    break;
                }
            }

            if(!valid){

                printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
                goto B;
            }
        }

    do{
        printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.Gender);

		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F'){

            ok =1;
		}

		else{

            ok =0;
		}

        if(!ok){

	    	printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
    	}

	 }while(!ok);

    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);

    do{
        C:
            printf("\n\t\t\tAddress: ");
            scanf("%s",p.Address);
            p.Address[0]=toupper(p.Address[0]);

            if(strlen(p.Address)>20||strlen(p.Address)<4){

                printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
                goto C;
            }

    }while(!valid);

    do{

        D:
            printf("\n\t\t\tContact no: ");
            scanf("%s",p.Contact_no);

            if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10){

                printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
                goto D;
            }

        else{

            for (b=0;b<strlen(p.Contact_no);b++){

                    if (!isalpha(p.Contact_no[b])){

                        valid=1;
                    }

                    else{

                        valid=0;
                        break;
                    }
                }

            if(!valid){

                printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
                goto D;
            }
        }
    }while(!valid);

    do{
        printf("\n\t\t\tEmail: ");
        scanf("%s",p.Email);
        if (strlen(p.Email)>30||strlen(p.Email)<8){

            printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
        }

    }while(strlen(p.Email)>30||strlen(p.Email)<8);

    E:
        printf("\n\t\t\tProblem: ");
        scanf("%s",p.Problem);
        p.Problem[0]=toupper(p.Problem[0]);

        if(strlen(p.Problem)>15||strlen(p.Problem)<3){

            printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
            goto E;
        }

        else{

            for (b=0;b<strlen(p.Problem);b++){

                if (isalpha(p.Problem[b])){

                    valid=1;
                }

                else{

                    valid=0;
                    break;
                }
            }

            if(!valid){

                printf("\n\t\t Problem contain Invalid character. Enter again.");
                goto E;
            }
        }

	F:
        printf("\n\t\t\tPrescribed Doctor:");
        scanf("%s",p.Doctor);
        p.Doctor[0]=toupper(p.Doctor[0]);

        if(strlen(p.Doctor)>30||strlen(p.Doctor)<3){

            printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
            goto F;
        }

        else{

            for (b=0;b<strlen(p.Doctor);b++){

                if (isalpha(p.Doctor[b])){

                    valid=1;
                }

                else{

                    valid=0;
                    break;
                }
            }
            if(!valid){

                printf("\n\t\t Doctor name contain Invalid character :(  Enter again :)");
                goto F;
            }
        }

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);

    G:
        getch();
        printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
        scanf(" %c",&ans);

        if (toupper(ans)=='Y'){

                Add();
        }

        else if(toupper(ans)=='N'){

            printf("\n\t\t Redirecting to the main menu... ");
            getch();
            MainMenu();
        }

        else{

            printf("\n\t\tInvalid Input\n");
            goto E;
        }
}

void list(void){

	int row;

	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t\t  !!!!!!!!!!!!!! Patients Record !!!!!!!!!!!!!\n");

        gotoxy(1,15);
		printf("Full Name");

		gotoxy(20,15);
		printf("Gender");

		gotoxy(32,15);
		printf("Age");

		gotoxy(37,15);
		printf("Address");

		gotoxy(49,15);
		printf("Contact No.");

		gotoxy(64,15);
		printf("Email");

		gotoxy(88,15);
		printf("Problem");

		gotoxy(98,15);
		printf("Prescribed Doctor\n");

		printf("=================================================================================================================");
		row=17;

		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name,
					&p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF){

			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);

			gotoxy(20,row);
			printf("%c",p.Gender);

			gotoxy(32,row);
			printf("%i",p.age);

			gotoxy(37,row);
			printf("%s",p.Address);

			gotoxy(49,row);
			printf("%s",p.Contact_no);

			gotoxy(64,row);
			printf("%s",p.Email);

			gotoxy(88,row);
			printf("%s",p.Problem);

			gotoxy(98,row);
			printf("%s",p.Doctor);

			row++;
		}

		fclose(ek);
		getch();
		MainMenu();
}

void dlt(void){

	char name[20];
	int found=0;

	system("cls");
	Title();

	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n");

	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);

	while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
			 &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF){

		if (strcmp(p.First_Name,name)!=0){

            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
		}

		else{

			printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
			found=1;
		}
	}

	if(found==0){

		printf("\n\n\t\t\t Record not found....");
		getch();
		MainMenu();
	}
	else{

		fclose(ek);
		fclose(ft);
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\t Record deleted successfully...");
		getch();
		MainMenu();
	}
}

void ext(void){

    system("cls");
	Title();
	printf("\n\n\n\n\n\tTHANK YOU FOR USING HMS BY VAIBHAV PRADHAN AND KRISHTI THAPA(BSC.IT 1ST YEAR). HAVE A GOOD DAY!  \n\n\n\n\n");
	getch();
	exit(1);
}

int main(){

    WelcomeScreen();
    Title();
    LoginScreen();
    MainMenu();

    return 0;
}
