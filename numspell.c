#include "../Header/bibhas.h"


void use(char *filename);
char* arrayToNumString(char *array,int start, int end);
char* rarrayToNumSring(int *array, int top);
void twoDigit(int *numberArray,char **digits,char **tens, char **dec,char **hun, int start,int end);
void hundred(int *numberArray,char **digits,char **tens, char **dec,char **hun, int digit);
void thousand(int *array,char **digits,char **tens, char **dec, char **hun, int digit);
void lakh(int *array,char **digits,char **tens, char **dec, char **hun, int digit);
void coror(int *array,char **digits,char **tens, char **dec, char **hun, int digit);
void numSpelling(char *num);


char* rarrayToNumString(int *array, int top)
{
    char *str = (char*)malloc(sizeof(char) * (top + 1));
    int k = 0;
    
    for (int i = top - 1; array[i] == 0 && i >= 0; i--)
        top--;

    for (int i = top - 1; i >= 0; i--)
    {
        int digit = array[i];
        str[k++] = digit + '0';  // Convert integer to character by adding '0'
    }
    
    str[k] = '\0';
    return str;
}




char* arrayToNumString(char *array, int start, int end)
{   
    //printf("\n[ * ] In arraytoNum func : array : %s, start : %d, adn end : %d",array,start,end);

    //Let left index positions has no 0s
    char *str = (char*)malloc(sizeof(char) * (end-start + 1));
    int k = 0;
    int index = start;

    for (int i = start; i<end; i++)
    {
	//printf("\n[ * ] value of i : %d, and array[%d] = %c",i,i,array[i]);
        
	if(array[i] == '0')
	{
		index++;
		//printf("\n[ * ] True");
    	}
	else
		break;
    }

    //printf("\n[ * ] afater remove left 0s first index : %d",index);

    for (int i = index; i < end; i++)
    {
	//printf("\n[ * ] first digit : %c",array[i]);
        str[k++] = array[i];  // Convert integer to character by adding '0'
    }
    
    str[k] = '\0';
    return str;
}















//0,1
void twoDigit(int *numberArray,char **digits,char **tens, char **dec,char **hun, int start,int end)
{ 
	if(numberArray[start]==0 && numberArray[end]>1)//starts from 20,30,40,.....
	{
		printf("%s ",dec[numberArray[end]-2]);
	}
	else if(numberArray[end]>1 && numberArray[start]!=0)//andy random 2 digits number greater than 20 
	{
		printf("%s ",dec[numberArray[end]-2]);
		printf("%s ",digits[numberArray[start]]);
	}
	else if(numberArray[end]==1)
	{
		printf("%s ",tens[numberArray[start]]);
	}
	else if (numberArray[end]==0 )
	{
		printf("%s ",digits[numberArray[start]]);
	}
}

//1,0,2

void hundred(int *numberArray,char **digits,char **tens, char **dec,char **hun, int digit)
{
	if(numberArray[0]==0 && numberArray[1]==0 && numberArray[2]!=0)
	{
		printf("%s ",digits[numberArray[2]]);
		printf("%s ",hun[0]);
		return;
	}
	else if(numberArray[2]!=0)
	{
		printf("%s ",digits[numberArray[2]]);
		printf("%s ",hun[0]);

	}
	
	numSpelling(rarrayToNumString(numberArray,digit-1));

	//twoDigit(numberArray,digits,tens,dec,hun,0,1);
}

//4,3,2,1
//0,0,0,(<=1)
//5,4,3,2,1
//0,0,0,1,1
void thousand(int *array,char **digits,char **tens, char **dec, char **hun, int digit)
{

	if(digit==5)
	{
		twoDigit(array,digits,tens,dec,hun,3,4);
		digit-=2;
	}
	else if(digit==4)
	{
		printf("%s ",digits[array[3]]);
		digit-=1;
	}
	printf("%s ",hun[1]);
	
	numSpelling(rarrayToNumString(array,digit));

	//hundred(array,digits,tens,dec,hun);
}


//7,6,5,4,3,2,1
void lakh(int *array,char **digits,char **tens, char **dec, char **hun, int digit)
{
	if(digit==7)
	{
		twoDigit(array,digits,tens,dec,hun,5,6);
		digit-=2;
	}
	else if(digit==6)
	{
		printf("%s ",digits[array[5]]);
		digit--;
	}
	
	printf("%s ",hun[2]);
	
	numSpelling(rarrayToNumString(array,digit));
	
	//thousand(array,digits,tens,dec,hun,digit);
}




void numSpelling(char *num)
{
   char *digits[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
   char *tens[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eightteen","nineteen","twenty"};
   char *dec[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
   char *hun[]={"hundred","thousand","lakh","coror"};

   //120

   //printf("\nInput string number : %s\n",num);
   
   int * numberArray=num2Array(num); //0,2

   int nDig=length(num);
   
   if(nDig==0)
   {
	   //printf("[ * ] exit by numm string");
	   return;
   }
   while(nDig>1 && numberArray[nDig-1]==0)
   	nDig--;


    if(nDig==1)
	    printf("%s ",digits[numberArray[0]]);

    else if (nDig==2)
    {
    	 twoDigit(numberArray,digits,tens,dec,hun,0,1);
    }
    //0,0,1
    else if(nDig==3)
    {
	 hundred(numberArray,digits,tens,dec,hun,nDig);
    }
    else if(nDig==4 || nDig==5)
    {
    	 thousand(numberArray,digits,tens,dec,hun,nDig);
    }
    else if(nDig==6 || nDig ==7)
    {
    	lakh(numberArray,digits,tens,dec,hun,nDig);
    }
    else if(nDig>7)
    {
	 //printf("\n[ * ] intering in coror function");
    	 
	char *num = rarrayToNumString(numberArray,nDig); 
	
	//printf("\n[ * ] the number is : %s",num);

	int start = 0, end = nDig % 7;//1 

	//printf("\n{ * } Redunadante digits : %d",end);
	
	if(end)
	{
		//printf("\n[ * ] redundate digigts are spell for corror");
		
		numSpelling(arrayToNumString(num,start,end));
		nDig -= end; // 7	
		printf("coror ");
	}	
	
	while( nDig >= 7 )
	{
			//printf("\n[ * ] rest lakh digits are spelling..");
			start = end;
		       	end = end + 7;	
			numSpelling(arrayToNumString(num,start,end));
			nDig -= 7;
			if(nDig)
				printf("coror ");	
	}
    }//coror formation
}






void use(char *filename)
{
   	printf("\n\tNumber Traslater");
	printf("\n\t-s\tconvert number to string");
	printf("\n\t-n\tconvert string to number");
	printf("\n\n\texamples:");
	printf("\n\t%s -s 123 [enter]",filename);
	printf("\n\t%s -n \"one hundrade twenty two\" [enter]\n\n",filename);	
}






void main(int args, char **argv)
{
	
	char *filename=argv[0];
	if(args==3)
	{
		argv++;
		for(int i=0;i<2;i++)
		{
			if( isEqual(argv[i],"-s") && isNum(argv[(i+1)%2]) )
			{
				numSpelling(argv[(i+1)%2]);
				return;
			}	
			else if( isEqual(argv[i],"-n") &&  isAlpha(argv[(i+1)%2]) )
			{
				printf("String to number is comming soon");
				lower(argv[(i+1)%2]);
				printf(" %s ",argv[(i+1)%2]);
				return;
			}
		}	
		use(filename);
	}
	else
	{
		use(filename);
	}
}

