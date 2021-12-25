#define BUFFER_SIZE 1000

char _TXT_[] = ".txt";
char txtFormat[15];
char _HELP_[]="help";

void loading(){
	printf("\n\tLoading: ");
	int i;
	for(i = 0; i<5; i++){
		printf("#");
		sleep(1);
	}
	printf("\n");
}

int mainMenu(){
	int choice;
	printf("\n\n\t1. Create new member\n\t2. Update members data\n\t3. Check members data\n\t4. List all data\n\t5. Transactions\n\t6. Delete member\n\t7. Reset system\n\t8. Exit\n\t");
	scanf("%d", &choice);
	return choice;
}

void dateTime(){
	time_t t;
	time(&t);
	printf("Date: %s",ctime(&t));
}

int fileExistsCheck(const char *fileName){

	FILE *file;
	if(file=fopen(fileName, "r")){
		fclose(file);
		return 1;
	}
	return 0;
}

void checkDateUpdate(int dd, int mm, int yy){
	if(yy>1900 && yy<=9999){
		if(mm>=1 && mm<=12){
			if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){

			}
			else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)){

			}
			else if((dd>=1 && dd<=28) && (mm==2)){

			}
			else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){

			}
			else{
				printf("\tDay is not valid! Wait few seconds and try again!\n");
				loading();
				system("cls");
				updateMembersData();
			}
		}
		else{
			printf("\tMonth is not valid! Wait few seconds and try again!\n");
			loading();
			system("cls");
			updateMembersData();
		}
	}
	else{
		printf("\tYear is not valid! Wait few seconds and try again!\n");
		loading();
		system("cls");
		updateMembersData();
		}
}

void backToMain(){
	dateTime();
	int btm;
	printf("\n\tSelect: \n\t1.Back to main menu \n\t0.Exit App\n\t");
	scanf("%d", &btm);
	switch(btm){
		case 1:
			system("cls");
			startMainProgram();
		break;
		case 0:
			exit(0);
		break;
		default:
			printf("\n\tWrong choice, enter 1 or 0, wait few seconds and try again!");
			fflush(stdin);
			loading();
			system("cls");
			backToMain();
	}
}

void updateString(char str[10], char name[10], int line){
	FILE * fPtr;
	FILE * fTemp;
	char buffer[BUFFER_SIZE];
	char newline[BUFFER_SIZE];
	int count;

	strcpy(_HELP_, str);
	fflush(stdin);

	printf("\n\tEnter new %s ", str);
	fgets(newline, BUFFER_SIZE, stdin);

	fPtr  = fopen(name, "r");
	fTemp = fopen("replace.tmp", "w");

	count = 0;
	while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
	{
		count++;

		if (count == line)
			fputs((strcat(_HELP_, newline)), fTemp);
		else
			fputs(buffer, fTemp);
	}

	fclose(fPtr);
	fclose(fTemp);

	remove(name);
	rename("replace.tmp", name);

	printf("\n\tSuccess!");
	printf("\n\t");
	system("pause");
	system("cls");
	backToMain();
}

void updateDate(char str[10], char name[10], int line){
	FILE * fPtr;
	FILE * fTemp;
	char buffer[BUFFER_SIZE];
	char newline[BUFFER_SIZE];
	int count, dd, mm, yy;

	strcpy(_HELP_, str);
	fflush(stdin);
	printf("\n\tEnter new %s ", str);
	fgets(newline, BUFFER_SIZE, stdin);
	printf("\n\tConfirm new %s ", str);
	scanf("%d/%d/%d", &dd, &mm, &yy);
	checkDateUpdate(dd, mm, yy);

	fPtr  = fopen(name, "r");
	fTemp = fopen("replace.tmp", "w");

	count = 0;
	while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
	{
		count++;

		if (count == line)
			fputs((strcat(_HELP_, newline)), fTemp);
		else
			fputs(buffer, fTemp);
	}

	fclose(fPtr);
	fclose(fTemp);

	remove(name);
	rename("replace.tmp", name);

	printf("\n\tSuccess!");
	printf("\n\t");
	system("pause");
	system("cls");
	backToMain();
}

void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

void startMainProgram(){
	dateTime();
	printf("\n\n\t\tBANK MANAGEMENT SYSTEM\n\t\t      by Dzenan");
	printf("\n\n\t###### Welcome to Main Menu! ######");
	switch(mainMenu()){
		case 1:
			sleep(1);
			newMember();
		break;
		case 2:
			sleep(1);
			updateMembersData();
		break;
		case 3:
			sleep(1);
			checkMembersData();
		break;
		case 4:
			sleep(1);
			listMembers();
		break;
		case 5:
			sleep(1);
			transactions();
		break;
		case 6:
			sleep(1);
			deleteMember();
		break;
		case 7:
			sleep(1);
			resetSystem();
		break;
		case 8:
			exit(0);
		break;
		default:
			printf("\n\tIncorrect choice! Wait few seconds!"); loading(); system("cls"); startMainProgram();
	}
}

void systemAccess(){
	dateTime();
	char password[] = "bankSystem2021";
	char compare[50];
	printf("\n\n\tEnter system password: ");
	scanf("%s", compare);
	if(strcmp(compare, password) == 0){
		printf("\n\tPassword match!");
		loading();
		system("cls");
		startMainProgram();
	}
	else if(strcmp(compare, "X")==0){
		exit(0);
	}
	else{
		printf("\n\tIncorrect password! Wait few seconds and try again or enter 'X' for exit app!\n");
		loading();
		system("cls");
		systemAccess();

	}
}

void deposit(char name[], char nameCopy[]){
    char converted[15];
    char buffer[BUFFER_SIZE];
    char newLine[BUFFER_SIZE];
    int count, line = 10, c;
    FILE *filePointer;
    FILE *fTemp;
    double balanceValue, newValue;

                system("cls");
				dateTime();

				filePointer = fopen(name, "r");
				count = 1;
				for(;;){
					c = fgetc(filePointer);
					if(EOF == c){
						break;
					}
					else if('\n' == c){
						++count;
						if(line == count){
							fgets(buffer, BUFFER_SIZE, filePointer);
						}
					}
				}
				fclose(filePointer);

				removeChar(buffer, 'B');
				removeChar(buffer, 'a');
				removeChar(buffer, 'l');
				removeChar(buffer, 'a');
				removeChar(buffer, 'n');
				removeChar(buffer, 'c');
				removeChar(buffer, 'e');
				removeChar(buffer, ':');
				removeChar(buffer, ' ');

				balanceValue = atof(buffer);

				printf("\n\tBalance: %.2lf$", balanceValue);
				printf("\n\tEnter deposit amount [MIN. 10$]: ");
				if(scanf("%lf", &newValue)){
                    if(newValue>=10){
                        balanceValue = balanceValue + newValue;

                        snprintf(converted, sizeof(converted), "%.2lf", balanceValue);
                        strcpy(newLine, converted);

                        strcpy(_HELP_, "Balance: ");
                        fflush(stdin);

                        filePointer  = fopen(name, "r");
                        fTemp = fopen("replace.tmp", "w");

                        count = 0;
                        while ((fgets(buffer, BUFFER_SIZE, filePointer)) != NULL)
                        {
                            count++;

                            if (count == line)
                                fputs((strcat(_HELP_, newLine)), fTemp);
                            else
                                fputs(buffer, fTemp);
                        }

                        fclose(filePointer);
                        fclose(fTemp);

                        remove(nameCopy);
                        rename("replace.tmp", nameCopy);

                        printf("\n\tSuccess! Your new balance is: %.2lf$", balanceValue);
                        printf("\n\t");
                        system("pause");
                        system("cls");
                        backToMain();
                    }
                    else if(newValue==0){
                        system("cls");
                        backToMain();
                    }
                    else{
                        printf("\n\tMinimal deposit is 10$! Wait few seconds and try again or enter '0' to back to main menu!");
                        fflush(stdin);
                        loading();
                        system("cls");
                        deposit(name, nameCopy);
                    }
                }
				else{
                    printf("\n\tWrong Input!");
                    fflush(stdin);
                    loading();
                    deposit(name, nameCopy);
				}
}

void withdraw(char name[], char nameCopy[]){
    char converted[15];
    char buffer[BUFFER_SIZE];
    char newLine[BUFFER_SIZE];
    int count, line = 10, c;
    FILE *filePointer;
    FILE *fTemp;
    double balanceValue, newValue;

                system("cls");
				dateTime();

				filePointer = fopen(name, "r");
				count = 1;
				for(;;){
					c = fgetc(filePointer);
					if(EOF == c){
						break;
					}
					else if('\n' == c){
						++count;
						if(line == count){
							fgets(buffer, BUFFER_SIZE, filePointer);
						}
					}
				}
				fclose(filePointer);

				removeChar(buffer, 'B');
				removeChar(buffer, 'a');
				removeChar(buffer, 'l');
				removeChar(buffer, 'a');
				removeChar(buffer, 'n');
				removeChar(buffer, 'c');
				removeChar(buffer, 'e');
				removeChar(buffer, ':');
				removeChar(buffer, ' ');

				balanceValue = atof(buffer);

				printf("\n\tBalance: %.2lf$", balanceValue);

				printf("\n\tEnter withdraw amount: ");
				scanf("%lf", &newValue);

				if(newValue>balanceValue+100){
					printf("\n\tYou do not have enough funds in your account! Wait few seconds and try again or enter '0' to back to main menu!");
					fflush(stdin);
					loading();
					system("cls");
					withdraw(name, nameCopy);
				}
				else if(newValue==0){
					system("cls");
					backToMain();
				}
				else{
					balanceValue = balanceValue - newValue;

					snprintf(converted, sizeof(converted), "%.2lf", balanceValue);
					strcpy(newLine, converted);

					strcpy(_HELP_, "Balance: ");
					fflush(stdin);

					filePointer  = fopen(name, "r");
					fTemp = fopen("replace.tmp", "w");

					count = 0;
					while ((fgets(buffer, BUFFER_SIZE, filePointer)) != NULL)
					{
						count++;

						if (count == line)
							fputs((strcat(_HELP_, newLine)), fTemp);
						else
							fputs(buffer, fTemp);
						}

					fclose(filePointer);
					fclose(fTemp);

					remove(nameCopy);
					rename("replace.tmp", nameCopy);

					printf("\n\tSuccess! Your new balance is: %.2lf$", balanceValue);
					printf("\n\t");
					system("pause");
					system("cls");
					backToMain();
				}
}
