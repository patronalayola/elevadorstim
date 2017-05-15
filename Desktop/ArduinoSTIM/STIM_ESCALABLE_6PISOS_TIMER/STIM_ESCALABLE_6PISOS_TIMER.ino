// Numero de pisos, NO ESCALABLE
int n = 6;

// Numero de selectores, NO ESCALABLE
int S = 9; // 7 (S) es el número de selectores que correspone a la fórmula S = 2n - 3, donde n es el numero de estaciones.

// Arreglos botones y selectores // NO ESCALABLE
int reg_1; int reg_2; int reg_3; int reg_4; int reg_5; int reg_6;
int Arreglo_botones[] = {0, reg_1, reg_2, reg_3, reg_4, reg_5, reg_6};
int Arreglo_selectores[9]; //S = 2*n - 3; S es el valor entre corchetes.

// PUERTA, NO ESCALABLE
int puerto_puerta = 21;
int s_puerta;

// Botones, NO ESCALABLE  
int boton_1 = 3; int e_boton_1;
int boton_2 = 4; int e_boton_2;
int boton_3 = 5; int e_boton_3;
int boton_4 = 6; int e_boton_4;
int boton_5 = 7; int e_boton_5;
int boton_6 = 8; int e_boton_6;
int bandera_boton;
int boton;

// Sensor fotoelectrico, NO ESCALABLE
int Opt; int puerto_optico = 9;

// Relevadores, NO ESCALABLE
int freno_pasivo = 10;
int puerto_sube = 11; int s_sube;
int puerto_baja = 12; int s_baja;

// Selectores, NO ESCALABLE
int selector_1 = A0;
int selector_2 = A1;
int selector_3 = A2;
int selector_4 = A3;
int selector_5 = A4;
int selector_6 = A5;
int selector_7 = A6;
int selector_8 = A7;
int selector_9 = A8;

// Timer
int timer;
int puerto_timer = A9;

// LEDS Y LETS, estos llevan un igual a algo que hace referencia a qué pines del Arduino está ocupando. NO ESCALABLE
int led_1 = 22; int led_2 = 24; int led_3 = 26; int led_4 = 28; int led_5 = 30; int led_6 = 32;
int Arreglo_leds[] = {0, led_1, led_2, led_3, led_4, led_5, led_6};
int let_1 = 34; int let_2 = 36; int let_3 = 38; int let_4 = 40; int let_5 = 42; int let_6 = 44; 
int Arreglo_lets[] = {0, let_1, let_2, let_3, let_4, let_5, let_6};

// Contadores de selectores, ESCALABLE
int i = 0;
int c = 0;
int POpt_0 = 0;
int POpt_1 = 0;
int nuevo_c;

// Variables de uso general, ESCALABLE
int x;
int f;
int g;
int contador_b_en1;
int j;
int estancia;

// Identificadores de sube o baja, ESCALABLE
int sube = 0;
int baja = 0;
int subiendo;
int bajando;
int transicion;

void leer_botones() //NO ESCALABLE
{
  e_boton_1 = digitalRead(boton_1); // e_boton_1 --> estado del boton 1.
  e_boton_2 = digitalRead(boton_2);
  e_boton_3 = digitalRead(boton_3);
  e_boton_4 = digitalRead(boton_4);
  e_boton_5 = digitalRead(boton_5);
  e_boton_6 = digitalRead(boton_6);
  guardar();
}

void guardar() //NO ESCALABLE.
{
  if (e_boton_1 == 1)
  {
    if ((Opt == 1)&&(POpt_1 == 1)&&(Arreglo_botones[1] == 0)) {
    Arreglo_botones[1] = 0; 
    digitalWrite(Arreglo_leds[1],LOW); 
    }
    else    {
      if ((sube == 0)&&(baja == 0)) {boton = 1;}
      Arreglo_botones[1] = 1;
      digitalWrite(Arreglo_leds[1],HIGH);
    }
    if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 1)) {Arreglo_botones[1] = 1; digitalWrite(led_1,HIGH);} // CON LED
    //if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 1)) {Arreglo_botones[1] = 1;} // SIN LED
  }
  
  if (e_boton_2 == 1)
  {
    if ((Opt == 1)&&(POpt_1 == 2)&&(Arreglo_botones[2] == 0)) {
    Arreglo_botones[2] = 0; 
    digitalWrite(Arreglo_leds[2],LOW); 
    }
    else    {
      if ((sube == 0)&&(baja == 0)) {boton = 2;}
      Arreglo_botones[2] = 1;
      digitalWrite(Arreglo_leds[2],HIGH);
    }
    if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 2)) {Arreglo_botones[2] = 1; digitalWrite(led_2,HIGH);} // CON LED
    // if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 2)) {Arreglo_botones[2] = 1;} // SIN LED
  }
  
  if (e_boton_3 == 1)
  {
    if ((Opt == 1)&&(POpt_1 == 3)&&(Arreglo_botones[3] == 0)) {
    Arreglo_botones[3] = 0; 
    digitalWrite(Arreglo_leds[3],LOW); 
    }
    else    {
      if ((sube == 0)&&(baja == 0)) {boton = 3;}
      Arreglo_botones[3] = 1;
      digitalWrite(Arreglo_leds[3],HIGH);
    }
    if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 3)) {Arreglo_botones[3] = 1; digitalWrite(led_3,HIGH);} // CON LED
    //if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 3)) {Arreglo_botones[3] = 1;} // SIN LED
  }

  if (e_boton_4 == 1)
  {
    if ((Opt == 1)&&(POpt_1 == 4)&&(Arreglo_botones[4] == 0)) {
    Arreglo_botones[4] = 0; 
    digitalWrite(Arreglo_leds[4],LOW); 
    }
    else    {
      if ((sube == 0)&&(baja == 0)) {boton = 4;}
      Arreglo_botones[4] = 1;
      digitalWrite(Arreglo_leds[4],HIGH);
    }
    if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 4)) {Arreglo_botones[4] = 1; digitalWrite(led_4,HIGH);} // CON LED
    //if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 4)) {Arreglo_botones[4] = 1;} // SIN LED
  }

  if (e_boton_5 == 1)
  {
    if ((Opt == 1)&&(POpt_1 == 5)&&(Arreglo_botones[5] == 0)) {
    Arreglo_botones[5] = 0; 
    digitalWrite(Arreglo_leds[5],LOW); 
    }
    else    {
      if ((sube == 0)&&(baja == 0)) {boton = 5;}
      Arreglo_botones[5] = 1;
      digitalWrite(Arreglo_leds[5],HIGH);
    }
    if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 5)) {Arreglo_botones[5] = 1; digitalWrite(led_5,HIGH);} // CON LED
    //if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 5)) {Arreglo_botones[5] = 1;} // SIN LED
  }

  if (e_boton_6 == 1)
  {
    if ((Opt == 1)&&(POpt_1 == 6)&&(Arreglo_botones[6] == 0)) {
    Arreglo_botones[6] = 0; 
    digitalWrite(Arreglo_leds[6],LOW); 
    }
    else    {
      if ((sube == 0)&&(baja == 0)) {boton = 6;}
      Arreglo_botones[6] = 1;
      digitalWrite(Arreglo_leds[6],HIGH);
    }
    if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 6)) {Arreglo_botones[6] = 1; digitalWrite(led_6,HIGH);} // CON LED
    //if ((estancia >= 1)&&(((digitalRead(puerto_sube)) == 1)||((digitalRead(puerto_baja)) == 1))&&(Opt == 1)&&(nuevo_c == 6)) {Arreglo_botones[6] = 1;} // SIN LED
  }
  
  if ((sube == 1)||(baja == 1))
  {
    if (Arreglo_botones[6] == 1)
    {
      boton = 6;
    }
    if (Arreglo_botones[5] == 1)
    {
      boton = 5;
    }
    if (Arreglo_botones[4] == 1)
    {
      boton = 4;
    }
    if (Arreglo_botones[3] == 1)
    {
      boton = 3;
    }
    if (Arreglo_botones[2] == 1)
    {
      boton = 2;
    }
    if (Arreglo_botones[1] == 1)
    {
      boton = 1;
    }
  }
  
  if ((Arreglo_botones[1] == 1)||(Arreglo_botones[2] == 1)||(Arreglo_botones[3] == 1)||(Arreglo_botones[4] == 1)||(Arreglo_botones[5] == 1)||(Arreglo_botones[6] == 1))
  {
    bandera_boton = 1;
  }
  else
  {
    bandera_boton = 0;
  }
  
}

void leer_selectores() //NO ESCALABLE
{
  Arreglo_selectores[1] = digitalRead(selector_1);
  Arreglo_selectores[2] = digitalRead(selector_2);
  Arreglo_selectores[3] = digitalRead(selector_3);
  Arreglo_selectores[4] = digitalRead(selector_4);
  Arreglo_selectores[5] = digitalRead(selector_5);
  Arreglo_selectores[6] = digitalRead(selector_6);
  Arreglo_selectores[7] = digitalRead(selector_7);
  Arreglo_selectores[8] = digitalRead(selector_8);
  Arreglo_selectores[9] = digitalRead(selector_9);
}

void imprimir() //NO ESCALABLE
{
  Serial.print(" B1:"); Serial.print(Arreglo_botones[1]);
  Serial.print(" B2:"); Serial.print(Arreglo_botones[2]);
  Serial.print(" B3:"); Serial.print(Arreglo_botones[3]);
  Serial.print(" B4:"); Serial.print(Arreglo_botones[4]);
  Serial.print(" B5:"); Serial.print(Arreglo_botones[5]);
  Serial.print(" B6:"); Serial.print(Arreglo_botones[6]);
  Serial.print(" boton:"); Serial.print(boton);
  Serial.print(" bandera_boton:"); Serial.print(bandera_boton);
  
  Serial.print(" POpt_1:"); Serial.print(POpt_1);
  Serial.print(" POpt_0:"); Serial.print(POpt_0);
  Serial.print(" nuevo_c:"); Serial.print(nuevo_c);
  Serial.print(" Todavia_1:"); Serial.print(contador_b_en1);

  Serial.print (" Estancia:"); Serial.print(estancia);
  
  Serial.print(" Opt:"); Serial.print(Opt);

  // if (j < n) {Serial.print(" A_botones[j]:"); Serial.print(Arreglo_botones[j]);} else {Serial.print(" A_botones[j]:"); Serial.print(Arreglo_botones[0]);}
  
  Serial.print(" Puerta:"); Serial.print(s_puerta);
  
  Serial.print(" SUBE:"); Serial.print(digitalRead(puerto_sube));
  Serial.print(" BAJA:"); Serial.print(digitalRead(puerto_baja)); 

  Serial.print(" j:"); Serial.print(j);
  Serial.print(" g:"); Serial.print(g);

  //Serial.print(" L1:"); Serial.print(digitalRead(Arreglo_leds[1]));
  //Serial.print(" L2:"); Serial.print(digitalRead(Arreglo_leds[2]));
  //Serial.print(" L3:"); Serial.print(digitalRead(Arreglo_leds[3]));  
  //Serial.print(" L4:"); Serial.print(digitalRead(Arreglo_leds[4]));
  //Serial.print(" L5:"); Serial.print(digitalRead(Arreglo_leds[5]));
  
  Serial.print(" P1:"); Serial.print(digitalRead(Arreglo_lets[1]));
  Serial.print(" P2:"); Serial.print(digitalRead(Arreglo_lets[2]));
  Serial.print(" P3:"); Serial.print(digitalRead(Arreglo_lets[3])); 
  Serial.print(" P4:"); Serial.print(digitalRead(Arreglo_lets[4]));
  Serial.print(" P5:"); Serial.print(digitalRead(Arreglo_lets[5]));
  Serial.print(" P6:"); Serial.print(digitalRead(Arreglo_lets[6]));  

  Serial.println("");
}

void r_5000() //ESCALABLE
{
  for (g = 1; g <= 30; g++) // Para este código, por el procesamiento, este retardo dura, para ese valor de g, 5 a 6 segundos.
  {
    leer_botones();
    imprimir();
    s_puerta = digitalRead(puerto_puerta);
    if (s_puerta == 0) {g = 31;}
    delay(10);
  }
}

void r_1500() //ESCALABLE
{
  for (g = 1; g <= 15; g++) // Para este código, por el procesamiento, este retardo dura, para ese valor de g, 1.5 seg
  {
    leer_botones();
    imprimir();
    delay(10);
  }
}

void apagar() //ESCALABLE
{
  digitalWrite(freno_pasivo,LOW);
  digitalWrite(puerto_sube,LOW);
  digitalWrite(puerto_baja,LOW);
}

void letreros() //ESCALABLE
{
  int d = 0;
  d = c + 1;
  for (int f = 1; f <= n; f++)
  {
    if (f == d)
    {
      digitalWrite(Arreglo_lets[f],HIGH);
    }
    else
    {
      digitalWrite(Arreglo_lets[f],LOW);
    }
  }
}

void cuenta_selectores() //ESCALABLE
{
  // El siguiente proceso genera los 2 tipos de contadores para los selectores.
  x = 1;
  i = 0;
  c = 0;
  while(x <= S)
  {
    if (x%2 == 0)
    {
      i = i + Arreglo_selectores[x];
    }
    else
    {
      c = c + Arreglo_selectores[x];
    }
    x++;
  }
}

void leer() //ESCALABLE
{
  leer_botones(); 
  leer_selectores();
  cuenta_selectores();
  letreros();
  s_puerta = digitalRead(puerto_puerta);
  Opt = digitalRead(puerto_optico);
  POpt_1 = c + 1; 
  POpt_0 = i + 1;  
  nuevo_c = c + 1;
  imprimir();
}

void tiempo()
{
  e_boton_1 = digitalRead(boton_1); // e_boton_1 --> estado del boton 1.
  e_boton_2 = digitalRead(boton_2);
  e_boton_3 = digitalRead(boton_3);
  e_boton_4 = digitalRead(boton_4);
  e_boton_5 = digitalRead(boton_5);
  e_boton_6 = digitalRead(boton_6);
  imprimir();
  if ((e_boton_1 == 1)||(e_boton_2 == 1)||(e_boton_3 == 1)||(e_boton_4 == 1)||(e_boton_5 == 1)||(e_boton_6 == 1))
  {timer = 1; digitalWrite(puerto_timer,HIGH);}
  guardar();
}

void puerta() 
{
  if (s_puerta == 0)
  {
    while (s_puerta == 0)
    {
      if (timer == 0)
      {tiempo();}
      s_sube = digitalRead(puerto_sube);
      s_baja = digitalRead(puerto_baja);
      if (s_sube == 1) {subiendo = 1; bajando = 0;}
      if (s_baja == 1) {bajando = 1; subiendo = 0;}
      apagar();
      leer();
      imprimir();
    }
    r_1500();
    if (subiendo == 1) {digitalWrite(freno_pasivo,HIGH); digitalWrite(puerto_sube,HIGH); digitalWrite(puerto_baja,LOW);}
    if (bajando == 1) {digitalWrite(freno_pasivo,HIGH); digitalWrite(puerto_baja,HIGH); digitalWrite(puerto_sube,LOW);}
    subiendo = 0; bajando = 0;
  }
}

void setup() //NO ESCALABLE
{
  Serial.begin(9600);
  
  //ENTRADAS____________
  
  //BOTONES
  pinMode(boton_1,INPUT);
  pinMode(boton_2,INPUT);
  pinMode(boton_3,INPUT);
  pinMode(boton_4,INPUT);
  pinMode(boton_5,INPUT);
  pinMode(boton_6,INPUT);

  //SELECTORES
  pinMode(selector_1,INPUT);
  pinMode(selector_2,INPUT);
  pinMode(selector_3,INPUT);
  pinMode(selector_4,INPUT);
  pinMode(selector_5,INPUT);
  pinMode(selector_6,INPUT);
  pinMode(selector_7,INPUT);
  pinMode(selector_8,INPUT);
  pinMode(selector_9,INPUT);

  //OPTICO  
  pinMode(puerto_optico,INPUT);
  
  //PUERTA
  pinMode(puerto_puerta,INPUT);

  //SALIDAS//_________________
  
  //RELEVADORES
  pinMode(puerto_sube,OUTPUT);
  pinMode(puerto_baja,OUTPUT);
  pinMode(freno_pasivo,OUTPUT);

  //PUERTO_TIMER
  pinMode(puerto_timer,OUTPUT);

  //LEDS POR BOTON
  //pinMode(led_1,OUTPUT);
  //pinMode(led_2,OUTPUT);
  //pinMode(led_3,OUTPUT);
  //pinMode(led_4,OUTPUT);
  //pinMode(led_5,OUTPUT);

  //INDICADORES DE PISO
  pinMode(let_1,OUTPUT);
  pinMode(let_2,OUTPUT);
  pinMode(let_3,OUTPUT);
  pinMode(let_4,OUTPUT);
  pinMode(let_5,OUTPUT);
  pinMode(let_6,OUTPUT);
}

void loop() 
{
  tiempo();

  if (timer == 1)
  {
    leer(); // lee contadores: c e i, botones, OPT.
    puerta();
    if ((Arreglo_botones[1] == 0)&&(Arreglo_botones[2] == 0)&&(Arreglo_botones[3] == 0)&&(Arreglo_botones[4] == 0)&&(Arreglo_botones[5] == 0)&&(Arreglo_botones[6] == 0))
    {timer = 0; digitalWrite(puerto_timer,LOW);}

  //PRIMERA ACCIÓN DE SUBIR O BAJAR.
  if ((bandera_boton == 1)&&(timer == 1))
  {
  leer();  
  if ((Opt == 0)&&(s_puerta == 1)) // usamos i  
  {
    if (boton > POpt_0) // la variable POpt_0 se encuentra en la función leer();
    {
      sube = 1;
      baja = 0;
      digitalWrite(puerto_sube,HIGH);
      digitalWrite(puerto_baja,LOW);
    }
    else if (boton == POpt_0)
    {
      sube = 0;
      baja = 1;
      digitalWrite(puerto_sube,LOW);
      digitalWrite(puerto_baja,HIGH);
    }
  }
  else if ((Opt == 1)&&(s_puerta == 1)) // usamos C
  {
    if (boton > POpt_1) // la variable POpt_1 se encuentra en la función leer();
    {
      sube = 1;
      baja = 0;
      digitalWrite(puerto_sube,HIGH);
      digitalWrite(puerto_baja,LOW);
    }
    else if (boton < POpt_1)
    {
      sube = 0; 
      baja = 1;
      digitalWrite(puerto_sube,LOW);
      digitalWrite(puerto_baja,HIGH);
    }
   }
  }

  
//YA QUE SE SABE SI VA A SUBIR O BAJAR
 while ((sube == 1)&&(timer == 1))
  {
    puerta();
    if (j!=(n+1)) {leer();}
  
    for (j = nuevo_c; j <= n; j++)
    {
      if (j != (n+1))
      {
        leer();
        if((Opt == 1)&&(Arreglo_botones[j] == 1)&&(j == nuevo_c)&&(estancia == 0))
        {
          apagar();
          Arreglo_botones[j] = 0;
          // digitalWrite(Arreglo_leds[j],LOW);
          r_5000();
          puerta();
          contador_b_en1 = 0;
          j = n;
        }
        if((Opt == 1)&&(j == nuevo_c)) {estancia = estancia + 1;} 
        if (estancia >= 5) {estancia = 5;}
        if(Opt == 0) {estancia = 0;}
      }
    }
     for (j = nuevo_c; j <= n; j++)
     {
      puerta();
      if (j != (n+1)) 
      {
        leer(); 
        if (Arreglo_botones[j] == 1) 
        {
          if (contador_b_en1 < (n - nuevo_c)) {contador_b_en1++;}
          else if(contador_b_en1 == (n-nuevo_c)) {contador_b_en1 = n-nuevo_c;}
        } 
      }
     }
     if (contador_b_en1 >= 1) {digitalWrite(puerto_sube,HIGH); digitalWrite(freno_pasivo,HIGH);}
     else if (contador_b_en1 == 0) {sube = 0;}  
  }
   
while ((baja == 1)&&(timer == 1))
  {
    puerta();
    if (j!=(0)) {leer();}
  
    for (j = nuevo_c; j >= 1; j--)
    {
      leer();
      if (j != (0))
      {
        if((Opt == 1)&&(Arreglo_botones[j] == 1)&&(j == nuevo_c)&&(estancia == 0))
        {
          apagar();
          Arreglo_botones[j] = 0;
          // digitalWrite(Arreglo_leds[j],LOW);
          r_5000();
          puerta();
          contador_b_en1 = 0;
          j = 1;
        }
        if((Opt == 1)&&(j == nuevo_c)) {estancia = estancia + 1;} 
        if (estancia >= 5) {estancia = 5;}
        if(Opt == 0) {estancia = 0;}
      }
    }
     for (j = nuevo_c; j >= 1; j--)
     {
      puerta();
      if (j != (0)) 
      {
        leer(); 
        if (Arreglo_botones[j] == 1) 
        {
          if (contador_b_en1 < (nuevo_c)) {contador_b_en1++;}
          else if(contador_b_en1 == (nuevo_c)) {contador_b_en1 = nuevo_c;}
        } 
      }
     }
     if (contador_b_en1 >= 1) {digitalWrite(puerto_baja,HIGH); digitalWrite(freno_pasivo,HIGH);}
     else if (contador_b_en1 == 0) {baja = 0;} 
  }  
  }
}



