void newMember(){
	FILE *filePointer;

	system("cls");
	dateTime();
	printf("\n\n\t\t####Create New Member####\n\n");

	typedef struct Member{
		int accountNumber;
		char name[10], lastName[15];
		int dd, mm, yy;
		int bdd, bmm, byy;
		char address[20];
		char citizenship[10];
		int years;
		char typeOfAccount[6];
		float balance;
	} Member;

	Member member;

	srand(time(0));
	member.accountNumber = rand();
	printf("\n\tAccount number is: %d\n", member.accountNumber);
	printf("\tEnter member name: ");
	scanf("%s", member.name);
	printf("\tEnter member last name: ");
	scanf("%s", member.lastName);

	int dateEnter(){

	void checkDate(int dd, int mm, int yy){
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
				newMember();
				}
			}
			else{
			printf("\tMonth is not valid! Wait few seconds and try again!\n");
			loading();
			system("cls");
			newMember();
			}
		}
		else{
		printf("\tYear is not valid! Wait few seconds and try again!\n");
		loading();
		system("cls");
		newMember();
		}
	}

		printf("\tEnter creation date [dd/mm/yyyy]: ");
		if(scanf("%d/%d/%d", &member.dd, &member.mm, &member.yy)){

		}
		else{
			printf("\tWrong date format! Restart the program! \n");
			exit(0);
		}
		checkDate(member.dd, member.mm, member.yy);

		printf("\tEnter birth date [dd/mm/yyyy]: ");
		if(scanf("%d/%d/%d", &member.bdd, &member.bmm, &member.byy)){

		}
		else{
			printf("\tWrong date format! Restart the program! \n");
			exit(0);
		}
		checkDate(member.bdd, member.bmm, member.byy);
	}

	dateEnter();
	printf("\tEnter member address: ");
	scanf("%s", member.address);
	printf("\tEnter member citizenship: ");
	scanf("%s", member.citizenship);
	printf("\tEnter how old the member is: ");
	scanf("%d", &member.years);

	if(member.years >= 16){

		member.balance = 0;

		printf("\tSelect account type: \n\t-Debit \n\t-Credit \n\t-Saving \n\t");
		scanf("%s", member.typeOfAccount);

		strcpy(txtFormat, member.name);
		strcat(txtFormat, _TXT_);
		filePointer = fopen(("%s",txtFormat), "w");
		fprintf(filePointer, "Account number: %d\nName: %s\nLast name: %s\nCreation date: %d/%d/%d\nDate of birth: %d/%d/%d\nAddress: %s\nCitizenship: %s\nYears: %d\nType of account: %s\nBalance: %.2f $", member.accountNumber, member.name, member.lastName, member.dd, member.mm, member.yy, member.bdd, member.bmm, member.byy, member.address, member.citizenship, member.years, member.typeOfAccount, member.balance);
		fclose(filePointer);

		printf("\n\tYou have successfully created a new account! Wait few seconds! \n");
		loading();
		system("cls");
		backToMain();
	}
	else{
		printf("\n\tPeople under 16 are not allowed to have an account!");
		loading();
		system("cls");
		backToMain();
	}
}

void checkMembersData(){
	static char name[10];
	FILE *filePointer;
	int bufferLength = 255;
	char buffer[bufferLength];

	system("cls");
	dateTime();

	printf("\n\t\t#####Check Members Data#####\n");
	printf("\n\tEnter member name: ");
	scanf("%s", name);
	strcat(name, _TXT_);

	if(fileExistsCheck(name)){
		system("cls");
		dateTime();
		printf("\n\t#####Check result:#####\n");

		printf("\n");
		filePointer = fopen(("%s", name), "r");
		while(fgets(buffer, bufferLength, filePointer)) {
			printf("\t");
    		printf("%s", buffer);
		}
		fclose(filePointer);

		printf("\n\n");
		system("pause");
		system("cls");
		backToMain();
	}
	else if(strcmp(name, "0.txt") == 0){
		system("cls");
		backToMain();
	}
	else{
		printf("\tMember does not exists! Wait few seconds and try again or enter '0' to back to main menu!");
		loading();
		checkMembersData();
	}

}

void updateMembersData(){
	static char name[10];
	int choice;

	system("cls");
	dateTime();

	printf("\n\t\t#####Update Members Data#####\n");
	printf("\n\tEnter memeber name: ");
	scanf("%s", name);
	strcat(name, _TXT_);

	if(fileExistsCheck(name)){

		printf("\n\tWhat you want to update? \n\t1.Account number \n\t2.Last name \n\t3.Creation date \n\t4.Date of birth \n\t5.Address \n\t6.Citizenship \n\t7.Years \n\t8.Type of account \n\t9.All \n\t0.Back to main menu \n\t");
		scanf("%d", &choice);
	 	sleep(1);
	 	system("cls");
	 	dateTime();

	 	switch(choice){

	 		case 1:
			    updateString("Account number: ", name, 1);
		    break;
		    case 2:
		    	updateString("Last name: ", name, 3);
		    break;
		    case 3:
		    	updateDate("Creation date: ", name, 4);
		    break;
		    case 4:
		    	updateDate("Date of birth: ", name, 5);
		    break;
		    case 5:
		    	updateString("Address: ", name, 6);
		    break;
		    case 6:
		    	updateString("Citizenship: ", name, 7);
		    break;
		    case 7:
		    	updateString("Years: ", name, 8);
		    break;
		    case 8:
		    	updateString("Type of account: ", name, 9);
		    break;
		    case 9:
		    	remove(name);
		    	newMember();
		    break;
		    case 0:
		    	system("cls");
		    	startMainProgram();
		    break;
		    default:
		    	printf("\n\tIncorrect choice! Wait few seconds!"); loading(); system("cls"); updateMembersData();
		}
	}
	else if(strcmp(name, "0.txt")==0){
		system("cls");
		backToMain();
	}
	else{
		printf("\tMember does not exists! Wait few seconds and try again or enter '0' to back to main menu!!");
		loading();
		updateMembersData();
	}
}

void listMembers(){

	system("cls");
	dateTime();
	printf("\n");

	printf("\n\t\t#####List All Data#####\n");

	DIR *d;
	char choice[5];
	FILE *filePointer;

    struct dirent *dir;
    d = opendir(".");
    if (d){
        while ((dir = readdir(d)) != NULL){
        	int length = strlen(dir->d_name);
        	if(strncmp(dir->d_name + length -4, _TXT_, 4) == 0){
			printf("\t%s\n", dir->d_name);
        	}
        }
        closedir(d);
    }

    printf("\n\tDo you want save this list to a .txt document? [YES/NO]\n\t");
    printf("\n\t");
    scanf("%s", choice);
    if(strcmp(choice, "YES") == 0){
        filePointer = fopen("DataList.txt", "w");
        d = opendir(".");
        if(d){
        	while ((dir = readdir(d)) != NULL){
        		int length = strlen(dir->d_name);
        		if(strncmp(dir->d_name + length -4, _TXT_, 4) == 0){
					fprintf(filePointer, "%s\n", dir->d_name);
        		}
        	}
        	closedir(d);
    	}
    	fclose(filePointer);
    	printf("\n\tSaved!");
	}
	else if(strcmp(choice, "yes") == 0){
		system("cls");
		printf("\n\tError! You must type 'YES'");
		loading();
		listMembers();
	}
	else if(strcmp(choice, "Yes") == 0){
		system("cls");
		printf("\n\tError! You must type 'YES'");
		loading();
		listMembers();
	}
	else if (strcmp(choice, "NO") == 0){
		system("cls");
		backToMain();
	}
	else{
		system("cls");
		printf("\n\tError! Wrong input format!");
		loading();
		listMembers();
	}

    printf("\n\n\t");
    system("pause");
    system("cls");
	backToMain();
}

void transactions(){
    char name[50], nameCopy[50];
    int choice;

	system("cls");
	dateTime();

	printf("\n\t\t#####Transactions#####\n");

	printf("\n\tEnter member name: ");
	scanf("%s", name);
	strcat(name, _TXT_);
    strcpy(nameCopy, name);

	if(fileExistsCheck(name)){

		printf("\n\tSelect: \n\t1.Deposit \n\t2.Withdraw \n\t");
		scanf("%d", &choice);
		sleep(1);

		switch(choice){
			case 1:
                deposit(name, nameCopy);
			break;
			case 2:
				withdraw(name, nameCopy);
			break;
			default:
				printf("\n\tIncorrect choice! Wait few seconds!"); fflush(stdin); loading(); system("cls"); transactions();
		}

	}
	else if(strcmp(name, "0.txt")==0){
		system("cls");
		backToMain();
	}
	else{
		printf("\tMember does not exists! Wait few seconds and try again or enter '0' to back to main menu!!");
		loading();
		transactions();
	}
}

void deleteMember(){
	char name[10];

	system("cls");
	dateTime();

	printf("\n\tEnter member name which you want delete: ");
	scanf("%s", name);
	strcat(name, _TXT_);

	if(fileExistsCheck(name)){

		remove(name);

		printf("\n\tMember is successfully deleted!");
	}
	else if(strcmp(name, "0.txt")==0){
		system("cls");
		backToMain();
	}
	else{
		printf("\n\tMember does not exists, wait few seconds and try again or enter '0' to back to main menu! ");
		loading();
		deleteMember();
	}

	printf("\n\t");
	system("pause");
	system("cls");
	backToMain();
}

void resetSystem(){
	int choice;
	DIR *d;
	FILE *filePointer;
	struct dirent *dir;
	int length;

	dateTime();
	system("cls");
	printf("\n\tSystem will be reseted! Are you sure? \n\t1.Yes \n\t2.No \n\t");
	scanf("%d", &choice);

	switch(choice){
		case 1:
			system("cls");
			dateTime();

		    d = opendir(".");
		    if (d){
		        while ((dir = readdir(d)) != NULL){
		        	length = strlen(dir->d_name);
		        	if(strncmp(dir->d_name + length -4, _TXT_, 4) == 0){
						remove(dir->d_name);
		        	}
		        }
		        closedir(d);
		    }

		    printf("\n\tSystem is successfully reseted!");
		    printf("\n\t");
		    system("pause");
		    system("cls");
		    backToMain();
		break;
		case 2:
			system("cls");
			backToMain();
		break;
		default:
			printf("\n\t Wrong choice, enter 1 or 2! Wait few seconds and try again!");
			loading();
			system("cls");
			resetSystem();
	}
}
