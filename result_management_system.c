#include <stdio.h>
#include<conio.h>
#include <string.h>


 struct Student {   // creating a structure variable to store different types data type in continuous memory loacation
    int rollNumber,total;
    char name[220];
    float odia_marks,english_marks,math_marks,physics_marks,chemistry_marks,biology_marks,secured,percentage;
 };

 void Teacher();
 void Show_Result();
 void add();

 int main()
 {
    int choose;
    
        printf("\n********Welcome to student result system***************  \n");
        printf("                         10th result                         \n");
        printf("*************************************************************\n");
        printf("|    1.Teacher   |    2.Show Result     |    3.Add Mark     |\n");
        printf("*************************************************************\n");
    do
    {    
        printf("Press 1 to chosse teacher input marks\n");
        printf("Press 2 to choose to show result\n");
        printf("Press 3 to add student result\n");
        printf("Please choose : \n");
        scanf("%d", &choose);//choose which work is done
        if (choose==2)
        {
            Show_Result();// calling to show_result function for showing result
        }else if(choose==1)
        {
            Teacher(choose);  // calling to teacher function for enter student mark by teacher          
        }
        else if(choose==3)
        {
            add(choose);   // calling to add function for add another student result if teacher want           
        } 
        else{
            printf("Invalid input choose");// if teacher could not choose any above from option it is show that
        }
        printf("\n");
    } while (choose>3 && choose<=0); // above statement is running until choose any function
    return 0;
 }

 void Teacher(){
 	char id[220];
    char passwd[220];
    printf("Enter teachers ID number\n");
    scanf("%s",&id);
    printf("Enter password\n");
    scanf("%s",&passwd);
     
    //here teacher add their students mark;***************************************************************************
    if(strcmp(id,"monster577")==0){     /* strcmp = structure compare is used to 
    compare between a fixed data to another data and here that is */
        if(strcmp(passwd,"Monster@1430")==0){ // and here data is password
               FILE *ptr; // creating file data type and store a pointer type variable
               struct Student students[50]; // take array of a student detail of their result 
               ptr = fopen("result.csv", "w"); /*open a file  in write mode and 
               it automatically creating a file in hard disk*/
               if (ptr == NULL) {/*if ptr have not a file or does nuot 
               give any location it gives file could not be created*/
               printf("File could not be created.");
               }
               // below line is use tofor print in csv file in top
               fprintf(ptr,"Roll No,Name,Odia,English,Math,Physics,Chemistry,Biology,Total,Secured,Percentage\n");
               // fprint used for print in file
               // it is csv file so if we take comma it understand print in next tab
               int i,n;
               printf("Enter number of student's mark want to entry : ");
               scanf("%d",&n);
               for (i = 0; i<n; i++){
                    printf("Enter details for student %d:\n", i + 1);
                     printf("Roll Number: ");
                     scanf("%d", &students[i].rollNumber);
                      printf("Name: ");
                      scanf("%s", students[i].name);
                      printf("odia Marks: ");
                      scanf("%f", &students[i].odia_marks);
                      printf("english Marks: ");
                      scanf("%f", &students[i].english_marks);
                      printf("math Marks: ");
                      scanf("%f", &students[i].math_marks);
                      printf("physics Marks: ");
                      scanf("%f", &students[i].physics_marks);
                      printf("chemistry Marks: ");
                      scanf("%f", &students[i].chemistry_marks);
                      printf("biology Marks: ");
                      scanf("%f", &students[i].biology_marks);
                      students[i].secured=students[i].odia_marks+students[i].english_marks+students[i].math_marks+students[i].physics_marks+students[i].chemistry_marks+students[i].biology_marks;
                      students[i].percentage=(students[i].secured/600)*100;
                      students[i].total=600;
               
                     fprintf(ptr,"%d,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%d,%.2f,%.2f\n",students[i].rollNumber,students[i].name,students[i].odia_marks,students[i].english_marks,students[i].math_marks,students[i].physics_marks,students[i].chemistry_marks,students[i].biology_marks,students[i].total,students[i].secured,students[i].percentage);
                }
               printf("Student details have been written to result.csv.\n");
               
               fclose(ptr);// it close the file
           }
    }
    else{
    	printf("Invalid User id or Password\n");// if in above passwrd or user name invalid it shows this type
	} 
}
void Show_Result(){
     printf("Show the marks of student\n");
     FILE*  ptr= fopen("result.csv", "r");// file open in read mode 
     if (ptr==NULL) {
        printf("Can't open file\n");
     }

     char buffer[1024];
     int row = 0;
     int column = 0;

     
     while (fgets(buffer, 1024, ptr)) { /*fgets=is used to
      reads a text line or a string from the specified file or 
      console and then stored into a string variable.
      buffer= it is used  to hold data temporarly
           while it being transferred from one place to another
           in c when reading from some place we use it.
      */
        column = 0;
        row++;
        if (row == 1) // Skip the header row
            continue;


        char* value = strtok(buffer,",");
        while (value) {
             if (column == 0) {
                printf("Roll No: ");
            } else if (column == 1) {
                printf("\tName : ");
            } else if (column == 2) {
                printf("\tOdia_Mark: ");
            } else if (column == 3) {
                printf("\tEnglish_Mark: ");
            } else if (column == 4) {
                printf("\tMath_Mark: ");
            } else if (column == 5) {
                printf("\tPhysics_Mark: ");
            } else if (column == 6) {
                printf("\tChemistry_Mark: ");
            } else if (column == 7) {
                printf("\tBiology_Mark: ");
            } else if (column == 8) {
                printf("\tTotal_Mark: ");
            } else if (column == 9) {
                printf("\tSecured_Mark: ");
            } else if (column == 10) {
                printf("\tPercentage: ");
            }   
            printf("%s", value);
            value = strtok(NULL, ","); 
            /* strtok is refer to structure token is used to
            splitting strings into token based on a sepation
            " , " is separate to string
            */  
            column++;
        }
    
      }
 
      fclose(ptr);
}
void add(){
    char id[220];
    char passwd[220];
    printf("Enter teachers ID\n");
    scanf("%s",&id);
    printf("Enter password\n");
    scanf("%s",&passwd);
     
    //here teacher add their students mark;***************************************************************************
  if(strcmp(id,"monster577")==0){
    if(strcmp(passwd,"Monster@1430")==0){
     FILE* ptr = fopen("result.csv", "a");//open file as add mode

     if (ptr==NULL) {
        printf("File is doesnot exists\n");
     }
     int i,n;
     printf("Enter how many number student's mark will be enter :\n");
     scanf("%d",&n);
     for(i=0;i<=n;i++){
        int rollNumber,total;
        char name[220];
        float odia_marks,english_marks,math_marks,physics_marks,chemistry_marks,biology_marks,secured,percentage;
    

         printf("Enter details for student %d:\n", i + 1);
                     printf("Roll Number: ");
                     scanf("%d", &rollNumber);
                      printf("Name: ");
                      scanf("%s",&name);
                      printf("odia Marks: ");
                      scanf("%f", &odia_marks);
                      printf("english Marks: ");
                      scanf("%f", &english_marks);
                      printf("math Marks: ");
                      scanf("%f", &math_marks);
                      printf("physics Marks: ");
                      scanf("%f", &physics_marks);
                      printf("chemistry Marks: ");
                      scanf("%f", &chemistry_marks);
                      printf("biology Marks: ");
                      scanf("%f", &biology_marks);
                      total=600;
                      secured=odia_marks+english_marks+math_marks+physics_marks+chemistry_marks+biology_marks;
                      percentage=(secured/600)*100;
                      
                    // below line is use to added value is stored in file
                     fprintf(ptr, "%d,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%d,%.2f,%.2f\n",rollNumber, name,odia_marks,english_marks,math_marks, physics_marks, chemistry_marks, biology_marks, total, secured,percentage);
     }
     fclose(ptr);//use to close to file
    printf("Data added successfully!\n");
    }
  }
  else{
    	printf("Invalid User id or Password\n");
	}

}