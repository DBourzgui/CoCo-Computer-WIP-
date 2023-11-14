#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const byte Row = 4;
const byte Col = 3;
char keys [Row] [Col] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'.', '0', '='}
};

byte rowPins[Row] = { 11, 6, 7, 9 };
byte colPins[Col] = { 10, 12, 8 };
/* 3, 8, 7, 5
   4, 2, 6  */
// empty, col2, row1, col1, row4, col3, row3, row2, empty


byte eye0[] = {
  B01110,
  B11011,
  B10001,
  B11011,
  B11111,
  B10001,
  B00000,
  B00000
};

byte eye1[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000
};

byte eye2[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte mouthL[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11000,
  B11111,
  B01111
};

byte mouthM[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte mouthR[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00011,
  B11111,
  B11110
};

byte bodyL[] = {
  B10111,
  B10110,
  B10110,
  B11110,
  B00110,
  B00110,
  B00110,
  B00111
};


byte bodyR[] = {
  B11100,
  B01100,
  B01100,
  B01100,
  B01100,
  B01100,
  B01100,
  B11100
};


char key;
char emps[3], etips[8], coco[8], dows[8], quarts[4], nicks[4], dimes[4], penns[4];
int i, flag = 0;
float sum = 0;
int empsI, pages, quartsI, nicksI, dimesI, pennsI;
float quartsT, nicksT, dimesT, pennsT, changeT;
float etipsF[2], cocoF[2], dowsF[2];

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, Row, Col);



void setup() {

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, eye0);
  lcd.createChar(1, eye1);
  lcd.createChar(2, eye2);
  lcd.createChar(3, mouthL);
  lcd.createChar(4, mouthM);
  lcd.createChar(5, mouthR);
  lcd.createChar(6, bodyL);
  lcd.createChar(7, bodyR);

  lcd.setCursor(0, 0);
  lcd.print(" The CoCo Computer!");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("From the Great Mind");
  lcd.setCursor(0, 3);
  delay(1000);
  lcd.print("of One D.Bourzgui :)");
  lcd.setCursor(6, 1);
  lcd.write(byte(6));
  lcd.write(byte(2));
  lcd.write(byte(4));
  lcd.write(byte(4));
  lcd.write(byte(4));
  lcd.write(byte(2));
  lcd.write(byte(7));
  delay(1000);
  lcd.setCursor(7, 1);
  lcd.write(byte(0));
  lcd.setCursor(11, 1);
  lcd.write(byte(0));
  delay(1000);
  lcd.setCursor(7, 1);
  lcd.write(byte(1));
  lcd.setCursor(11, 1);
  lcd.write(byte(1));
  delay(250);
  lcd.setCursor(7, 1);
  lcd.write(byte(2));
  lcd.setCursor(11, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(1));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
  lcd.write(byte(1));
  delay(250);
  lcd.setCursor(7, 1);
  lcd.write(byte(1));
  lcd.setCursor(11, 1);
  lcd.write(byte(1));
  delay(250);
  lcd.setCursor(7, 1);
  lcd.write(byte(0));
  lcd.setCursor(11, 1);
  lcd.write(byte(0));
  delay(1000);
  lcd.setCursor(7, 1);
  lcd.write(byte(2));
  lcd.setCursor(11, 1);
  lcd.write(byte(2));
  delay(250);
  lcd.setCursor(7, 1);
  lcd.write(byte(1));
  lcd.setCursor(11, 1);
  lcd.write(byte(1));
  delay(250);
  lcd.setCursor(7, 1);
  lcd.write(byte(0));
  lcd.setCursor(11, 1);
  lcd.write(byte(0));
  delay(3000);
  lcd.clear();

}

void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select a Program:");
  lcd.setCursor(0, 1);
  lcd.print("1: Coin Counter");
  lcd.setCursor(0, 2);
  lcd.print("2: Tip Calculator");

  do {
    key = kpd.getKey();
  } while (key == NO_KEY);

  if (key != NO_KEY && key == '1') {

    flag = 0;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Loading Coin Counter");
    lcd.setCursor(6, 2);
    lcd.write(byte(6));
    lcd.write(byte(0));
    lcd.print(" o ");
    lcd.write(byte(0));
    lcd.write(byte(7));
    lcd.setCursor(8, 1);
    lcd.print(".");
    delay(550);
    lcd.setCursor(9, 1);
    lcd.print(".");
    lcd.setCursor(7, 2);
    lcd.write(byte(1));
    lcd.setCursor(11, 2);
    lcd.write(byte(1));
    delay(550);
    lcd.setCursor(10, 1);
    lcd.print(".");
    lcd.setCursor(7, 2);
    lcd.write(byte(2));
    lcd.setCursor(11, 2);
    lcd.write(byte(2));
    delay(550);
    lcd.setCursor(8, 1);
    lcd.print("   ");
    lcd.setCursor(7, 2);
    lcd.write(byte(1));
    lcd.setCursor(11, 2);
    lcd.write(byte(1));
    delay(550);
    lcd.setCursor(8, 1);
    lcd.print(".");
    lcd.setCursor(7, 2);
    lcd.write(byte(0));
    lcd.setCursor(11, 2);
    lcd.write(byte(0));
    delay(550);
    lcd.setCursor(9, 1);
    lcd.print(".");
    delay(550);
    lcd.setCursor(10, 1);
    lcd.print(".");
    delay(1500);


    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter the # of");
    lcd.setCursor(0, 1);
    lcd.print("quarters counted:");

    i = 0;

    do {
      key = kpd.getKey();
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
        quarts[i] = key;
        lcd.setCursor((18 + i), 1);
        lcd.print(key);
        i++;
      }
    } while (key != '=');

    quartsI = atoi(quarts);
    quartsT = quartsI * 0.25;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter the # of");
    lcd.setCursor(0, 1);
    lcd.print("dimes counted:");

    i = 0;

    do {
      key = kpd.getKey();
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
        dimes[i] = key;
        lcd.setCursor((15 + i), 1);
        lcd.print(key);
        i++;
      }
    } while (key != '=');

    dimesI = atoi(dimes);
    dimesT = dimesI * 0.10;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter the # of");
    lcd.setCursor(0, 1);
    lcd.print("nickels counted:");

    i = 0;

    do {
      key = kpd.getKey();
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
        nicks[i] = key;
        lcd.setCursor((17 + i), 1);
        lcd.print(key);
        i++;
      }
    } while (key != '=');

    nicksI = atoi(nicks);
    nicksT = nicksI * 0.05;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter the # of");
    lcd.setCursor(0, 1);
    lcd.print("pennies counted:");

    i = 0;

    do {
      key = kpd.getKey();
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
        penns[i] = key;
        lcd.setCursor((17 + i), 1);
        lcd.print(key);
        i++;
      }
    } while (key != '=');

    pennsI = atoi(penns);
    pennsT = pennsI * 0.01;

    changeT = pennsT + nicksT + dimesT + quartsT;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You Entered:");
    lcd.setCursor(0, 1);
    lcd.print("Qs - ");
    lcd.print(quartsI);
    lcd.print(" Ns - ");
    lcd.print(nicksI);
    lcd.setCursor(0, 2);
    lcd.print("Ds - ");
    lcd.print(dimesI);
    lcd.print(" Ps - ");
    lcd.print(pennsI);
    lcd.setCursor(0, 3);
    lcd.print("Press'='to continue!");

    do {
      key = kpd.getKey();
    } while (key != '=');

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Change Total: $");
    lcd.print(changeT);
    lcd.setCursor(0, 1);
    lcd.print("Qs-$");
    lcd.print(quartsT);
    lcd.print(" Ns-$");
    lcd.print(nicksT);
    lcd.setCursor(0, 2);
    lcd.print("Ds-$");
    lcd.print(dimesT);
    lcd.print(" Ps-$");
    lcd.print(pennsT);
    lcd.setCursor(0, 3);
    lcd.print("Press'='to continue!");
    do {
      key = kpd.getKey();
    } while (key != '=');


  }
  else if (key != NO_KEY && key == '2') {

    flag = 0;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Loading Tip Calc.");
    lcd.setCursor(6, 2);
    lcd.write(byte(6));
    lcd.print("$");
    lcd.print(" o ");
    lcd.print("$");
    lcd.write(byte(7));
    lcd.setCursor(8, 1);
    lcd.print(".");
    delay(350);
    lcd.setCursor(7, 2);
    lcd.print(' ');
    lcd.setCursor(11, 2);
    lcd.print(' ');
    delay(350);
    lcd.setCursor(7, 2);
    lcd.print('$');
    lcd.setCursor(11, 2);
    lcd.print('$');
    lcd.setCursor(9, 1);
    lcd.print(".");
    lcd.setCursor(9, 2);
    lcd.print("O");
    delay(350);
    lcd.setCursor(7, 2);
    lcd.print(' ');
    lcd.setCursor(11, 2);
    lcd.print(' ');
    delay(350);
    lcd.setCursor(7, 2);
    lcd.print('$');
    lcd.setCursor(11, 2);
    lcd.print('$');
    lcd.setCursor(10, 1);
    lcd.print(".");
    lcd.setCursor(9, 2);
    lcd.print("o");
    delay(350);
    lcd.setCursor(7, 2);
    lcd.print(' ');
    lcd.setCursor(11, 2);
    lcd.print(' ');
    delay(350);
    lcd.setCursor(7, 2);
    lcd.print('$');
    lcd.setCursor(11, 2);
    lcd.print('$');
    lcd.setCursor(8, 1);
    lcd.print("   ");
    lcd.setCursor(9, 2);
    lcd.print("O");
    delay(350);
    lcd.setCursor(7, 2);
    lcd.print(' ');
    lcd.setCursor(11, 2);
    lcd.print(' ');
    delay(350);
    lcd.setCursor(7, 2);
    lcd.print('$');
    lcd.setCursor(11, 2);
    lcd.print('$');
    lcd.setCursor(8, 1);
    lcd.print(".");
    lcd.setCursor(9, 2);
    lcd.print("o");
    delay(550);
    lcd.setCursor(9, 1);
    lcd.print(".");
    delay(550);
    lcd.setCursor(10, 1);
    lcd.print(".");
    delay(1500);


    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Total # of");
    lcd.setCursor(0, 1);
    lcd.print("employees that");
    lcd.setCursor(0, 2);
    lcd.print("worked today:");

    do {
      key = kpd.getKey();
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
        emps[i] = key;
        lcd.setCursor((14 + i), 2);
        lcd.print(key);
        i++;
      }
    } while (key != '=');

    i = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Total $ Amount");
    lcd.setCursor(0, 1);
    lcd.print("of E-tips made:");

    do {
      key = kpd.getKey();
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
        etips[i] = key;
        lcd.setCursor((15 + i), 1);
        lcd.print(key);
        i++;
      }
    } while (key != '=');

    i = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Total $ Amount");
    lcd.setCursor(0, 1);
    lcd.print("of Cash Tips from");
    lcd.setCursor(0, 2);
    lcd.print("Coco:");

    do {
      key = kpd.getKey();
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
        coco[i] = key;
        lcd.setCursor((5 + i), 2);
        lcd.print(key);
        i++;
      }
    } while (key != '=');

    i = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Total $ Amount");
    lcd.setCursor(0, 1);
    lcd.print("of Cash Tips from");
    lcd.setCursor(0, 2);
    lcd.print("Dows:");

    do {
      key = kpd.getKey();
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
        dows[i] = key;
        lcd.setCursor((5 + i), 2);
        lcd.print(key);
        i++;
      }
    } while (key != '=');

    empsI = atoi(emps);
    etipsF[0] = atof(etips);
    cocoF[0] = atof(coco);
    dowsF[0] = atof(dows);

    float T_tot = etipsF[0] + cocoF[0] + dowsF[0];

    char emphrs[empsI];
    float emphrsF[empsI];

    for (int j = 0; j < empsI; j++) {
      i = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter the # of hours");
      lcd.setCursor(0, 1);
      lcd.print("Employee #");
      lcd.setCursor(10, 1);
      lcd.print(j + 1);
      lcd.setCursor(0, 2);
      lcd.print("worked:");
      do {
        key = kpd.getKey();
        if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == '.')) {
          emphrs[i] = key;
          lcd.setCursor((8 + i), 2);
          lcd.print(key);
          Serial.print(emphrs[i]);
          i++;
        }
      } while (key != '=');
      emphrsF[j] = atof(emphrs);
      Serial.print(emphrsF[j]);
      memset(emphrs, 0, sizeof(emphrs));
    }

    for (int j = 0; j < empsI; j++) {
      sum = sum + emphrsF[j];
    }


    float T_Rate = T_tot / sum;

    for (int j = 0; j < empsI; j++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Employee #");
      lcd.print(j + 1);
      lcd.print(" earned:");
      lcd.setCursor(0, 1);
      lcd.print("$");
      lcd.print(emphrsF[j] * T_Rate);
      do {
        key = kpd.getKey();
      } while (key != '=');
    }

    if (empsI <= 4) {
      pages = 2;
    }
    else if (empsI <= 8) {
      pages = 3;
    }
    else if (empsI <= 12) {
      pages = 4;
    }
    else if (empsI <= 16) {
      pages = 5;
    }
    else {
      pages = 5;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Too many employees,");
      lcd.setCursor(0, 1);
      lcd.print("full breakdown not shown.");
      lcd.setCursor(6, 2);
      lcd.write(byte(6));
      lcd.print('X');
      lcd.setCursor(9, 2);
      //lcd.write(byte(4));
      lcd.write(byte(4));
      //lcd.write(byte(4));
      lcd.setCursor(11, 2);
      lcd.print('X');
      lcd.write(byte(7));
      delay(500);
      lcd.setCursor(7, 2);
      lcd.print('*');
      lcd.setCursor(11, 2);
      lcd.print('*');
      delay(1000);
      lcd.setCursor(7, 2);
      lcd.print('X');
      lcd.setCursor(11, 2);
      lcd.print('X');
      delay(500);
      lcd.setCursor(7, 2);
      lcd.print('*');
      lcd.setCursor(11, 2);
      lcd.print('*');
      delay(1000);
      lcd.setCursor(7, 2);
      lcd.print('X');
      lcd.setCursor(11, 2);
      lcd.print('X');
      delay(3000);
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Breakdown (pg 1/");
    lcd.print(pages);
    lcd.print(")");
    lcd.setCursor(0, 1);
    lcd.print("# of Employees: ");
    lcd.print(empsI);
    lcd.setCursor(0, 2);
    lcd.print("Tip Total: $");
    lcd.print(T_tot);
    lcd.setCursor(0, 3);
    lcd.print("Tip Rate/Hr: $");
    lcd.print(T_Rate);
    do {
      key = kpd.getKey();
    } while (key != '=');

    int k = 1;
    for (int j = 0; j < (pages - 1); j++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("#");
      lcd.print(k);
      lcd.print(": ");
      lcd.print(emphrsF[k - 1] * T_Rate);
      if (k <= empsI) {
        lcd.setCursor(0, 1);
        lcd.print("#");
        lcd.print(k + 1);
        lcd.print(": ");
        lcd.print(emphrsF[k] * T_Rate);
      }
      if (k <= empsI) {
        lcd.setCursor(0, 2);
        lcd.print("#");
        lcd.print(k + 2);
        lcd.print(": ");
        lcd.print(emphrsF[k + 1] * T_Rate);
      }
      if (k <= empsI) {
        lcd.setCursor(0, 3);
        lcd.print("#");
        lcd.print(k + 3);
        lcd.print(": ");
        lcd.print(emphrsF[k + 2] * T_Rate);
      }
      k = k + 4;
      do {
        key = kpd.getKey();
      } while (key != '=');
    }

    memset(emphrs, '\0', sizeof(emphrs));
    memset(emps,  '\0', sizeof(emps));
    memset(etips,  '\0', sizeof(etips));
    memset(coco,  '\0', sizeof(coco));
    memset(dows,  '\0', sizeof(dows));
    memset(emphrsF, 0, sizeof(emphrsF));
    memset(etipsF, 0, sizeof(etipsF));
    memset(cocoF, 0, sizeof(cocoF));
    memset(dowsF, 0, sizeof(dowsF));

    i, k, empsI, pages = 0;
    sum, T_Rate, T_tot = 0;
  }
  else {
    flag = 1;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Invalid Program #");
    lcd.setCursor(0, 1);
    lcd.print("Please Try Again!");
    lcd.setCursor(6, 2);
    lcd.write(byte(6));
    lcd.print('X');
    lcd.setCursor(9, 2);
    //lcd.write(byte(4));
    lcd.write(byte(4));
    //lcd.write(byte(4));
    lcd.setCursor(11, 2);
    lcd.print('X');
    lcd.write(byte(7));
    delay(500);
    lcd.setCursor(7, 2);
    lcd.print('*');
    lcd.setCursor(11, 2);
    lcd.print('*');
    delay(1000);
    lcd.setCursor(7, 2);
    lcd.print('X');
    lcd.setCursor(11, 2);
    lcd.print('X');
    delay(500);
    lcd.setCursor(7, 2);
    lcd.print('*');
    lcd.setCursor(11, 2);
    lcd.print('*');
    delay(1000);
    lcd.setCursor(7, 2);
    lcd.print('X');
    lcd.setCursor(11, 2);
    lcd.print('X');
    delay(3000);
  }

  if (flag != 1) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Please Reset the");
    lcd.setCursor(0, 1);
    lcd.print("Calculator Before");
    lcd.setCursor(0, 2);
    lcd.print("Starting Again! I'm");
    lcd.setCursor(0, 3);
    lcd.print("too lazy to do it...");
    delay(3000);

    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.write(byte(6));
    lcd.write(byte(2));
    lcd.print(" . ");
    lcd.write(byte(2));
    lcd.write(byte(7));

    /*z
     *zz
     *zzZ
     *zzZZ
     * zzZZ
     *z  zzZZ
    */
  }

}
