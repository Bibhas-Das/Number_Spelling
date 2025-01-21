#include <stdio.h>
#include <stdlib.h>

#define __START__ void main(int args,char **argv){
#define  __END__ }
#define bool int
#define true 1
#define false 0
#define string char*

//////////////////////////////////////  DECLARATIONS   //////////////////////////////////////////////
void sleep(long seconds);

int checkPrime(long year);
int isNum(char *str);

int isAlpha(char *str);
void lower(char *str);
void upper(char *str);

long Integer(char *str);
long countDigit(long num);
long revNum(long num);
int * num2Array(char *num);
long find(char* str,char* sub);
long rfind(char *str, char *sub, long start, long end);



long gcd(long num1,long num2);


long length(char *str);

int isEqual(char *str1,char *str2);

long stringToNum(char *str);

char* desimalToBinary(long number);
long binaryToDesimal(char *str);

char* slice(char *str, int start, int end);


char* scan(int input_length);


char** split(char *str, char dm);
char** tokenize(char *str);
void printList(char **list);
void freeList(char **list);


void str_concat(char *str1, char *str2);
void str_copy(char *str1, char *str2);
bool str_compare(string str1, string str2);


char* read(char *filename);
int write(char *filename, char *str, char *mode);


void gotoxy(int x, int y);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


void gotoxy(int x, int y) 
{
    printf("\033[%d;%dH", y, x);
}


long stringToNum(char *str)
{
	long num=0;
	//123
	if(isNum(str))
	{
		for(long i=0;str[i]!='\0'; i++)
		{
			num = (num *10) + (str[i] - '0');
		}

	}
	return num;

}



bool str_compare(string str1, string str2)
{
	size_t len1 = length(str1);
	size_t len2 = length(str2);

	if(len1!=len2)
	{
		return false;
	}
	else
	{
		while(*str2!='\0')
		{
			//printf("\n%c - %c",*str1,*str2);
			if(*str1!=*str2)
				return false;
			*str1++;
			*str2++;
		}
		return true;
	
	}
}



void str_copy(char *str1, char *str2)
{
	long strlen = length(str2);
	char *temp = (char*) realloc(str1,sizeof(char)*(strlen+1));
	if(!temp)
		return;
	for(long i=0; i<strlen; i++)
	{
		temp[i]=str2[i];
	}
	temp[strlen]='\0';
	str1=temp;
}





void str_concat(char *str1, char *str2) 
{
    
    while (*str1!='\0') 
        str1++; 
    
    while (*str2!='\0') 
        *str1++ = *str2++;
    
    *str1 = '\0'; 
}







char* scan(int input_length)
{
	char *str = (char*)malloc(sizeof(char)*input_length);
	fgets(str,input_length,stdin);
	int i=0;
	for(i=0;str[i+1]!='\0';i++);
	str[i]='\0';
	return str;
}



long countDigit(long num)
{
	long count=0;
	while(num) {  count++; num/=10; }
	return count;
}


long revNum(long num)
{
	long reverse=0;
	while(num){  reverse=(reverse*10)+num%10;  num/=10; }
	return reverse;
}

int * num2Array(char *num) //string number to interger array. Ex: "012", "34", etc
{
	int * numArray= (int*)malloc(sizeof(int));
	if(!numArray)
		return NULL;

	int j=0;
	for (int i=length(num)-1;i>=0;i--)
	{
		int dig=num[i]-'0';//interger type-casting
		numArray[j]=dig;
		j++;

		int *temp = (int*)realloc(numArray,sizeof(int)*(j+1));
		if(!temp)
		{
			free(numArray);
			return NULL;
		}
		numArray=temp;

	}

	return numArray;
}



int isNum(char *str)
{
    for(long i=0;*(str+i)!='\0';i++)
    {
        if(!(*(str+i)>='0' && *(str+i)<='9'))
        return 0;
    }
    return 1;
}

//' ' space is also concider as alpha bets
int isAlpha(char *str)
{
	for(long i=0;*(str+i)!='\0';i++)
	{
		if(  !(  *(str+i)==' ' || (*(str+i)>='A' && *(str+i)<='Z')  ||   (*(str+i)>='a' && *(str+i)<='z'))  )
		{
			return 0;
		}
	}
	return 1;
}


void lower(char *str)
{
	for(long i=0;*(str+i)!='\0';i++)
	{
		if(  *(str+i)>='A' && *(str+i)<='Z'  )
			*(str+i)=(*(str+i)-'A')+'a';
	}
}

void upper(char *str)
{
	for(long i=0;*(str+i)!='\0';i++)
	{
		if(  *(str+i)>='a' && *(str+i)<='z'  )
			*(str+i)=(*(str+i)-'a')+'A';
	}
}

long Integer(char *str)//12
{
    long num=0;
    for(long i=0;*(str+i)!='\0';i++)
    {
        num = (num * 10) +(*(str+i)-'0');  //1
    }
    return num;
}

long length(char *str)// "-c\0"
{
    long len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int isEqual(char *str1,char *str2)
{
    long len1=length(str1);
    long len2=length(str2);

    if(len1 > len2)
    {
        for(long i=0; i<len1;i++)
        {
            if(*(str1+i) != *(str2+i))
            return 0;
        }
    }
    else
    {
        for(long i=0; i<len2;i++)
        {
            if(*(str2+i) != *(str1+i))
            return 0;
        }
    }
    return 1;
}





char* desimalToBinary(long number) 
{
    static char binaryString[9];
    binaryString[8] = '\0';

    for (int i = 7; i >= 0; i--) 
    {
        binaryString[i] = (number & 1) ? '1' : '0';
        number >>= 1;
    }

    return binaryString;
}



long binaryToDecimal(char *binaryString) 
{
    long len = length(binaryString);
    long decimal = 0;

    for (long i = 0; i < len; i++) 
    {
        decimal = decimal * 2 + (binaryString[i] - '0');
    }

    return decimal;
}



int checkPrime(long year)
{
    if(year<2)
        return 0;
    for(long i = 2; i*i <= year;i++)
    {
        if(year%i==0)
        return 0;
    }
    return 1;
}



long gcd(long a,long b)
{
	while (b)
	{
		long t=b;	
		b=a%b;
	 	a=t;
	}
	return a;
}





void sleep(long seconds)
{
	for(long i=0;i<10000*seconds;i++)for(long j=0;j<30000;j++);
}




//"Hello world", "world"
long find(char *str, char *sub)
{
	for(long i=0;*(str+i)!='\0';i++)
	{
		if(sub[0]==str[i])
		{
			long k=i+1;
			int flag_same=1;
			for(int j=1;sub[j]!='\0';j++)
			{
				if(sub[j]!=str[k])
				{
					flag_same=0;
					break;
				}
				k++;
			}
			if(flag_same==1)
				return i;
		}
	}
	return -1;
}


long rfind(char *str, char *sub, long start, long end)
{
	if(end>=0 && start >=0 && start < end && length(str)>=end )
	{
		for(long i=start;start<=end;i++)
		{
			if(sub[0]==str[i])
			{
				long k=i+1;
				int flag_same=1;
				for(int j=1;sub[j]!='\0';j++)
				{
					if(sub[j]!=str[k])
					{
						flag_same=0;
						break;
					}
					k++;
				}
				if(flag_same==1)
					return i;
			}
		}
		return -1;
	}
	else
		return -1;
}






char** split(char *str,char dm)
{
    int sub_len = 20;
    int flag_space = 0, i, j = 0, list_index = 0;
    char substr[sub_len];

    char **List = (char**)malloc(sizeof(char *));
    if (!List)
        return NULL;

    for (i = 0; *(str + i) != '\0'; i++)
    {
        if (*(str + i) == dm && flag_space == 0)
            continue;
        else if (*(str + i) != dm && flag_space == 0)
            flag_space = 1;

        if (flag_space == 1 && *(str + i) == dm)
        {
            substr[j] = '\0';

            List[list_index] = (char*)malloc(j + 1);
            
	    if (!List[list_index])
            {
                for (int k = 0; k < list_index; k++)
                    free(List[k]);
                free(List);
                return NULL;
            }

            for (int k = 0; k <= j; k++)
                List[list_index][k] = substr[k];// including NULL chracter

            list_index++;
            flag_space = 0;
            j = 0;

            char **temp = (char**)realloc(List, sizeof(char*) * (list_index + 1));
            
	    if (!temp)
            {
                for (int k = 0; k < list_index; k++)
                    free(List[k]);
                free(List);
                return NULL;
            }
            List = temp;
        }
        else if (flag_space == 1)
        {
            substr[j++] = *(str + i);
        }
    }

 
    if (flag_space == 1)
    {
        substr[j] = '\0';

        List[list_index] = (char*)malloc(j + 1);
        if (!List[list_index])
        {
            for (int k = 0; k < list_index; k++)
                free(List[k]);
            free(List);
            return NULL;
        }

        for (int k = 0; k <= j; k++)
            List[list_index][k] = substr[k];  // Copy including the '\0'

        list_index++;

        char **temp = (char**)realloc(List, sizeof(char*) * (list_index + 1));
        if (!temp)
        {
            for (int k = 0; k < list_index; k++)
                free(List[k]);
            free(List);
            return NULL;
        }
        List = temp;
    }

    List[list_index] = NULL;

    return List;
}






//"  #$@How are you?# ??" => "you" "?
//"#$varibale is equal to number?? of this;"
char** tokenize(char *str)
{
    int sub_len = 50;
    int flag_space = 0,flag_special = 0, flag_alpha=0, i, j = 0, list_index = 0;
    char substr[sub_len];

    char **List = (char**)malloc(sizeof(char *));
    if (!List)
        return NULL;


    int alpha=-1,flag_separate=0;


    for (i = 0; i<length(str); i++)
    {
	//chaking if the character is alphabet or not
	if(  (*(str+i)>='A' && *(str+i)<='Z')  ||   (*(str+i)>='a' && *(str+i)<='z') )
	{
		if(alpha ==0)
			flag_separate=1;
		alpha=1;
	}
	else if (*(str+i)==' ')
		alpha=-1;	
	else
	{
		if(alpha==1)
			flag_separate=1;
		alpha=0;
	}
	//////////////////////////////////////////////

	
	//first occurance special chracters before reaching a alphabet from left to right
        if ( alpha == -1 && flag_space == 0)
            continue;
        else if (  alpha==1  && flag_space == 0)
	{    
		flag_space = 1;
		flag_alpha=1;
	}
	else if(  alpha==0  && flag_space == 0  )
	{
		flag_space = 1; 
		flag_special=1;
	}
	////////////////////////////////////////////////

	//started to store the characters and its functions
	//if a word end OR ant special chracte(s) occures before or end of a word then It will separate in a diffrent string
        //"are you? ??"  => "are\0" 
	if ( (flag_space == 1 && *(str + i) == ' ') || flag_separate)
        {

            substr[j] = '\0';

            List[list_index] = (char*)malloc(j + 1);
            
	    if (!List[list_index])
            {
                for (int k = 0; k < list_index; k++)
                    free(List[k]);
                free(List);
                return NULL;
            }

            for (int k = 0; k <= j; k++)
                List[list_index][k] = substr[k];// including NULL chracter
		

            list_index++;
            j = 0;


            char **temp = (char**)realloc(List, sizeof(char*) * (list_index + 1));
            
	    if (!temp)
            {
                for (int k = 0; k < list_index; k++)
                    free(List[k]);
                free(List);
                return NULL;
            }
            List = temp;

	    flag_separate=0;
		
        }


	//"  !@bibhas? Das?"

        if (flag_space == 1 && alpha != -1)
        {
            substr[j++] = *(str + i);
        }
    }



    if (flag_space == 1)
    {
        substr[j] = '\0';

        List[list_index] = (char*)malloc(j + 1);
        if (!List[list_index])
        {
            for (int k = 0; k < list_index; k++)
                free(List[k]);
            free(List);
            return NULL;
        }

        for (int k = 0; k <= j; k++)
            List[list_index][k] = substr[k];  // Copy including the '\0'
 
	list_index++;

        char **temp = (char**)realloc(List, sizeof(char*) * (list_index + 1));
        if (!temp)
        {
            for (int k = 0; k < list_index; k++)
                free(List[k]);
            free(List);
            return NULL;
        }
        List = temp;
    }

    List[list_index] = NULL;

    return List;
}






void printList(char **list)
{
	if(list)
	{
		int i=0;
		printf("\nList :");
	 	for(i=0;list[i]!=NULL;i++)
		{     
			printf(" [%d]=>%s",i,list[i]);
		}
		printf("\n");
	}
}

	


void freeList(char **list)
{
	if(list)
	{
		for(int i=0;list[i]!=NULL;i++)
			free(list[i]);
		free(list);
	}
}





char * slice(char *str, int start, int end)
{
	int len;
	if(start>=0 && end >= 0 && start <= end)
		len=(end-start)+1;
	else if(start<0 && end <0 && start >= end)
		len=start-end;
	
	char *substr = (char*)malloc(sizeof(char)*len);
	
	int j=0;

	int lenString=length(str);
	
	if(start>=0 && start<=end && end <= lenString)
	{
		for(int i=start;i<end;i++)
			substr[j++]=str[i];
	}
	else if(start < 0 && start >= end && lenString+end >= 0)
	{
		for(int i = lenString+start; i > lenString+end; i--)
			substr[j++]=str[i];

	}

	substr[j]='\0';
	return substr;
}
//slice(str,1,4);  => ibh/123






char* read(char *filename)
{
	FILE *fptr;
	fptr=fopen(filename,"r");
	if(fptr==NULL)
		return NULL;

	char *str = (char*)malloc(sizeof(char));
	long index=0;

	char ch;
	while( (ch=fgetc(fptr))!= EOF )
	{
		str[index++]=ch;
		char *temp = (char*)realloc(str,sizeof(char)*index+1);
		if(!temp)
		{
			free(str);
			return NULL;
		}
		else
		{
			str=temp;
		}
	}
	fclose(fptr);
	str[index]='\0';

	return str;
}


//Mode w/a
int write(char *filename, char *str, char *mode)
{
	FILE *fptr;
	for(int i=0;mode[i]!='\0';i++)
	{
		if(mode[i]!='w' && mode[i]!='a' && mode[i]!='+' && mode[i]!='b')
			return 0;
	}

	fptr = fopen(filename,mode);	
		fprintf(fptr,str);
	fclose(fptr);
	return 1;
}

