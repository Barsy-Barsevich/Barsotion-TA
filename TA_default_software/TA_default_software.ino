#include "Sevseg595_Barsotion.h"
//https://github.com/Barsy-Barsevich/Sevseg595_Barsotion
/**
 * A simple 7-segment via 74hc595 library
 * 
 * Available symbols:
 * Hex numbers:
 * 0 1 2 3 4 5 6 7 8 9 A b c d E F
 * Non-hex letters:
 * G H h I i J L n O o P q r S t U u Y
 * Special symbols:
 * _ - = [ ] " ' . ,
 * Space
 * 
 * 7-segment & 74hc595 wiring:
 * msb_first = true:
 * |Q0|Q1|Q2|Q3|Q4|Q5|Q6|Q7|
 * |A |B |C |D |E |F |G |DP|
 * msb_first = false:
 * |Q0|Q1|Q2|Q3|Q4|Q5|Q6|Q7|
 * |DP|G |F |E |D |C |B |A |
 * 
 * Common cathode - invert = false
 * Common anode - invert = true
 */


const int cs = 8;  //RCLK - 12 pin
const int sck = 40;  //SRCLK - 11 pin
const int d = 26;   //SER - 14 pin

void cs_set(uint8_t val) {digitalWrite(cs, val);}
void sck_set(uint8_t val) {digitalWrite(sck, val);}
void data_set(uint8_t val) {digitalWrite(d, val);}

sevseg_t sevseg;


void setup()
{
    pinMode(38, OUTPUT);
    digitalWrite(38, HIGH);
    Serial.begin(115200);
    pinMode(39, OUTPUT);
    pinMode(cs, OUTPUT);
    pinMode(sck, OUTPUT);
    pinMode(d, OUTPUT);
    sevseg.msb_first = true;
    sevseg.invert = true; //common cathode
    sevseg.cs_pin_set = cs_set;
    sevseg.sck_pin_set = sck_set;
    sevseg.data_pin_set = data_set;
}

void loop()
{
    Serial.println("Goida!");
    digitalWrite(39, LOW);
    sevseg_print(&sevseg, 'G');
    delay(500);
    sevseg_print(&sevseg, 'o');
    delay(500);
    sevseg_print(&sevseg, 'i');
    delay(500);
    sevseg_print(&sevseg, 'd');
    delay(500);
    sevseg_sh(&sevseg, ~0b00101010);
    delay(500);
    sevseg_print(&sevseg, ' '); //printing a space
    digitalWrite(39, HIGH);
    delay(2000);
}
