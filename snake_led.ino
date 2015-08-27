// Auth : Arabella BRAYER
// Date : 26/08/2015
// file : test

byte ledPin[] = {2,3,4,5,6,7,8,9,10,11};
int direction = 1;
int LED = 0;
int DELAY = 75;
int CUR_PARCOURS = 0;
int NB_PRS = 5;
int NUM_OF_BOUND = 0; // variable qui compte le nb de boucle d'un parcours

void setup() {
  // put your setup code here, to run once:
  for(int x =0; x < 10; x++)
  {
    pinMode(ledPin[x], OUTPUT);
    digitalWrite(ledPin[x], LOW);  
  }
}

void parcours(int num)
{
  switch(num)
  {
    case 0:
      parcours1();
    break;
    
    case 1:
      parcours2();
    break;
    
    case 2:
      parcours3();
    break;    

    case 3:
      parcours4();
    break;        

    case 4:
      parcours5();
    break;    
//    default:
//      parcours1();
//    break;
  }
}

void parcours1()
{
  while(NUM_OF_BOUND < 3)
  {
    digitalWrite(ledPin[LED], HIGH);
    delay(DELAY);
    digitalWrite(ledPin[LED], LOW);
    LED += direction;
    if (LED == 0) 
    { 
      NUM_OF_BOUND += 1;
      direction = 1;
    }
  else if (LED == 9) { direction = -1; }
  }
  NUM_OF_BOUND = 0;
}

void parcours2()
{
  int LED2 = LED + 1;
  while(NUM_OF_BOUND < 3)
  {
    digitalWrite(ledPin[LED], HIGH);
    digitalWrite(ledPin[LED2], HIGH);
    delay(DELAY);
    digitalWrite(ledPin[LED], LOW);
    digitalWrite(ledPin[LED2], LOW);
    LED += direction;
    LED2 += direction;
    if (LED == 0) 
    { 
      NUM_OF_BOUND += 1;
      direction = 1;
    }
  else if (LED == 8) { direction = -1; }
  }
  NUM_OF_BOUND = 0;
}

void parcours3()
{
  int LED2 = LED + 1;
  int LED3 = LED2 +1;
  while(NUM_OF_BOUND < 3)
  {
    digitalWrite(ledPin[LED], HIGH);
    digitalWrite(ledPin[LED2], HIGH);
    digitalWrite(ledPin[LED3], HIGH);    
    delay(DELAY);
    digitalWrite(ledPin[LED], LOW);
    digitalWrite(ledPin[LED2], LOW);
    digitalWrite(ledPin[LED3], LOW);    
    LED += direction;
    LED2 += direction;
    LED3 += direction;
    if (LED == 0) 
    { 
      NUM_OF_BOUND += 1;
      direction = 1;
    }
  else if (LED == 7) { direction = -1; }
  }
  NUM_OF_BOUND = 0;
}

void parcours4()
{
  int count =0;
  while(NUM_OF_BOUND < 8)
  {
    digitalWrite(ledPin[LED], HIGH);
    delay(DELAY);
    if(LED > count)
      { digitalWrite(ledPin[LED], LOW); }
    LED += direction;
    if (LED == count) 
    { 
      NUM_OF_BOUND += 1;
      direction = 1;
    }
  else if (LED == 9) { direction = -1; count += 1; }
  }
  NUM_OF_BOUND = 0;
  for(LED =9; LED >=0; LED--)
  {  digitalWrite(ledPin[LED], LOW);
    delay(DELAY);
  }
  LED = 0;
}

void parcours5()
{
  for(int count =0; count < 3 ; count++)
  {
    for(LED =0; LED < 10; LED++)
      {digitalWrite(ledPin[LED], HIGH); // allume tout 
    }
    delay(DELAY-20);
    for(LED =0; LED < 9; LED++)
      {digitalWrite(ledPin[LED], LOW); // éteint tout 
    }
    delay(DELAY-20);
  }
  digitalWrite(ledPin[9], LOW);
  LED = 0;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  parcours(CUR_PARCOURS);
  CUR_PARCOURS = (CUR_PARCOURS + 1) % NB_PRS;
}
