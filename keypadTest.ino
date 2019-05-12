


byte colum[] = {28,26,24,22};
byte row[] = {36,34,32,30};
const char keyMap[4][4] ={
                    {'1','2','3','A'},
                    {'4','5','6','B'},
                    {'7','8','9','C'},
                    {'*','0','#','D'},
                       };
#define DELAY_TIME 50


void setup() {

  for (byte i = 0 ; i <= 3 ; i++)
  {
    pinMode(colum[i], OUTPUT);
    pinMode(row[i], INPUT);
    digitalWrite(row[i], 1);
  }

  Serial.begin(9600);
}

void loop()
{



  for (byte i = 0; i <= 3; i++)
  {
    digitalWrite(colum[i], 0);
    for (byte j = 0; j <= 3; j++)
    {
      if (!digitalRead(row[j]))
      {
        delayMicroseconds(DELAY_TIME);          //switch debounce
        if (!digitalRead(row[j]))
        {
          Serial.println(keyMap[j][i]);
          /**
           * 
           * 
           * 
           * 
           * 
           * 
           * 
          */
          while(!digitalRead(row[j]));
        }
      }
    }
    digitalWrite(colum[i], 1);
  }
}
