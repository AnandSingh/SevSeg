#include <stdio.h>

//#define A 7
//#define B 8
//#define C 2
//#define D 3
//#define E 4
//#define F 6
//#define G 5

//#define printfprintf
//#define printfgcc printf

#define delay 

/*

 A
 ____
 |    |
 F|_G__| B
 E|    | C
 |____|
 D
 */
#define VALID_PTRN 11

int LedPattern[VALID_PTRN ][7] = {
  { 
    0,0,0,0,0,0,0                         }
  , // OFF
  { 
    0,1,1,0,0,0,0                         }
  , //1
  { 
    1,1,0,1,1,0,1                         }
  , //2
  { 
    1,1,1,1,0,0,1                         }
  , //3
  { 
    0,1,1,0,0,1,1                         }
  , //4
  { 
    1,0,1,1,0,1,1                         }
  , //5
  { 
    1,0,1,1,1,1,1                         }
  , //6
  { 
    1,1,1,0,0,0,0                         }
  , //7
  { 
    1,1,1,1,1,1,1                         }
  , //8
  { 
    1,1,1,1,0,1,1                         }
  , //9
  { 
    1,1,1,1,1,1,0                         } //0
};

int ledsys[7][7] ={
  {     
    1,0,0,0,0,0,0                         }
  , // OFF
  {     
    0,1,0,0,0,0,0                         }
  , //1
  {     
    0,0,1,0,0,0,0                         }
  , //2
  {     
    0,0,0,1,0,0,0                         }
  , //3
  {     
    0,0,0,0,1,0,0                         }
  , //4
  {     
    0,0,0,0,0,1,0                         }
  , //5
  {     
    0,0,0,0,0,0,1                         }
  //6

};
#define MAX_LED 7
#define MAX_PATTERN 256

int ipat = 0;
int lrn_ipat = 0;
int mem_ptrn[MAX_PATTERN][MAX_LED] = {
  0};
int lrn_ptrn[MAX_PATTERN][MAX_LED] = {
  0};



int learned = 0;

void display_led(int a, int b, int c, int d, int e, int f, int g)
{
//  digitalWrite(A, a);
//  digitalWrite(B, b);
//  digitalWrite(C, c);
//  digitalWrite(D, d);
//  digitalWrite(E, e);
//  digitalWrite(F, f);
//  digitalWrite(G, g);

}

void clr(void)
{
 // display_led(LOW, LOW, LOW, LOW, LOW, LOW, LOW);

}

/*

 A
 ____
 |    |
 F|_G__| B
 E|    | C
 |____|
 D
 
 a, b, c , d , e , f , g
 */
void LedSeg(int dischar)
{
  int led[7] = {
    0,0,0,0,0,0,0                        };
  //clear the previous data
  display_led(0,0,0,0,0,0,0);
  for(int i=0;i<7;i++)
  {
    led[i] = LedPattern[dischar][i];
  }
  display_led(led[0], led[1], led[2], led[3], led[4], led[5], led[6]);
}


/*

void setup()
{
  //Setup our pins
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  Serial.begin(9600); //Begin serial communcation



}*/





void dump_mem_ptrn()
{
  printf(" ==================================== ");

  printf("[%d]\n",ipat);
  for(int i = 0; i<ipat; i++)
  {
    for(int j=0; j<MAX_LED; j++ )
    {
      //printf(" ");
      printf("%d ",mem_ptrn[i][j]);
    }
    printf("\n");
  }
}

void dump_lrn_ptrn()
{
  printf(" ==================================== ");
  //printf("[%d]\n",lrn_ipat);

  printf("Original Pttarn\n");
  
  for(int i = 0; i<VALID_PTRN; i++)
  {
    for(int j=0; j<MAX_LED; j++ )
    {
      //printf(" ");
      printf("%d ",LedPattern[i][j]);
    }
    printf("\n");
  }
   printf(" ==================================== ");
  printf("[%d]\n",lrn_ipat);
  for(int i = 0; i<lrn_ipat; i++)
  {
    for(int j=0; j<MAX_LED; j++ )
    {
      //printf(" ");
      printf("%d ",lrn_ptrn[i][j]);
    }
    printf("\n");
  }

}
void save_mem_ptrn(int *i)
{
  if(ipat < MAX_PATTERN)
  {
    for(int j =0; j<MAX_LED;j++)
    {
      mem_ptrn[ipat][j] = i[j];
    }
    ipat++;
  }
 //printf("==== MEM ====\n");
}
void save_lrn_ptrn(int *i)
{
  if(lrn_ipat < MAX_PATTERN)
  {
    for(int j =0; j<MAX_LED;j++)
    {
      lrn_ptrn[lrn_ipat][j] = i[j];
    }
    lrn_ipat++;
  }
  //printf("==== LRN ====\n");
}

int chk_mem_ptrn(int *i)
{
  int ret = 0;
  for(int j =0; j< ipat; j++)
  {
    if((mem_ptrn[j][0] == i[0])
      && (mem_ptrn[j][1] == i[1])
      && (mem_ptrn[j][2] == i[2])
      && (mem_ptrn[j][3] == i[3])
      && (mem_ptrn[j][4] == i[4])
      && (mem_ptrn[j][5] == i[5])
      && (mem_ptrn[j][6] == i[6]))
    {
      ret = 1;
      break;
    }
  }
  //printf("\t\t %d\n",ret);
  return ret;

}
int chk_lrn_ptrn(int *i)
{
int ret = 0;
  for(int j =0; j< VALID_PTRN; j++)
  {
    if((LedPattern[j][0] == i[0])
      && (LedPattern[j][1] == i[1])
      && (LedPattern[j][2] == i[2])
      && (LedPattern[j][3] == i[3])
      && (LedPattern[j][4] == i[4])
      && (LedPattern[j][5] == i[5])
      && (LedPattern[j][6] == i[6]))
    {
      ret = 1;
      break;
    }
  }
 // printf("\t\t %d\n",ret);
  return ret;
}

int mov_ptrn[MAX_LED] = { 
  0,0,0,0,0,0,0 };
int seed_ptr[MAX_LED] = { 
    0,0,0,0,0,0,0         };
  int d = 0;

void find_nxt_ptr(int first, int sec,int pos,int *ptr, int inv)
{

  int temp_ptr[MAX_LED] = { 
    0,0,0,0,0,0,0         };

  
  for(int i =0; i<MAX_LED; i++)
  {
	temp_ptr[i] = mov_ptrn[i];
  }
  //printf("\n");


  // mov the moving pattern based on position
  
  for(int i = 0; i<pos;i++)
  {
    for(int j=(MAX_LED-1); j>=0;j--)
    {
      
      if(j==0)
      {
	if(inv ==0)
        {
         temp_ptr[j] = 0;
         }
        else{
        temp_ptr[j] = 1;
	}
      }
      else
      {
	temp_ptr[j] = temp_ptr[j-1]; 
      } 
    }
  }

  // Final Pattern to test
  //printf("\t");
  for(int i =0; i<MAX_LED; i++)
  {
    if(inv == 0)
    {
      ptr[i] = seed_ptr[i] | temp_ptr[i];
    }
    else
    {
      ptr[i] = seed_ptr[i] & temp_ptr[i];
    }
    //printf("%d ",ptr[i]);
  }
  //display_led(ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6]);
  delay(800);

}

void chk_ptrn(int *led)
{

   //check if that pattern already exist in memory pattern
   if( 0 == chk_mem_ptrn(led))
   {
        // check if it's a new learned pattern
      if(1 == chk_lrn_ptrn(led))
      {
          save_lrn_ptrn(led); // if yes then save it as learned pattern
      }
      save_mem_ptrn(led); //if no then save it as memory pattern
       //display_led(led[0], led[1], led[2], led[3], led[4], led[5], led[6]);
   }
}

int learningProcess()
{
  int round = 0;
  int firstcycle = 0;
  int secondcycle = 0;
  int ii = 0;
  int led[MAX_LED] = { 0,0,0,0,0,0,0 };
  int temp[MAX_LED] = { 0,0,0,0,0,0,0 };
  // clear any previous display
  int curr_seed_idx = 0;
  int mem_idx =0;
  clr();

  chk_ptrn(led);

  while(curr_seed_idx < MAX_LED)
  {
  	  //prepare the seed pattern
	  printf("-----%d------\n",curr_seed_idx);
	  for(int i = 0; i<MAX_LED; i++)
	  {
	    seed_ptr[i] = ledsys[curr_seed_idx][i];
	    printf("%d ",seed_ptr[i]);
	  }
	  printf("\n");
	  curr_seed_idx++;

  	  secondcycle = ipat;
          mem_idx = 0;
	  while(secondcycle > 0)
	  {
                printf("\t [%d %d]: ", secondcycle, mem_idx);
	  	for(int i = 0; i<MAX_LED; i++)
	  	{
			led[i] =  mem_ptrn[mem_idx][i] | seed_ptr[i];
			printf("%d ",led[i]);
		}
	
                printf("\n");
		// check pattern
	 	chk_ptrn(led);
                secondcycle--;
		mem_idx++;
	  }
  }

  return 0;
}

void loop()
{
	for(int i =0 ;i<MAX_PATTERN;i++)
	{
		for(int j =0 ;j<MAX_LED;j++)
		{
			mem_ptrn[i][j] = 0;
			lrn_ptrn[i][j] = 0;
		}
	}

	printf("--------------------------------\n");
	learningProcess();
	printf("Dump Lrn\n");
	dump_lrn_ptrn();
	printf("Dump mem\n");
	dump_mem_ptrn();

}



void main()
{
  loop();
}











