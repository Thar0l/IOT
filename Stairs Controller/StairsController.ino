/*
    Stairs controller
    Turns on LED strips from down stairs to up or from up to down. Direction depends on signals from two PIR motion sensors.
    modified 21 January 2016
    by Gusarov Aleksei (https://vk.com/Thar0l)
    puplished at https://github.com/Thar0l/IOT
 */
//STAIRS OPTIONS
const int stairs_count = 11;

//ARDUINO PINOUT
const int up_pir_pin   = 14;
const int down_pir_pin = 15;
const int stairs_pins[stairs_count] = {2,3,4,5,6,7,8,9,10,11,12};


//TIME OPTIONS
const int light_delay = 1000; //ms
const int check_delay = 100;  //ms

//SYSTEM VARIABLES
enum 
{
    st_wait = 0,
    st_up   = 1,
    st_down = 2
} state;



//START INITIALISATION
void setup() 
{
    pinMode(up_pir_pin, INPUT);
    pinMode(down_pir_pin, INPUT);
    for (int i = 0; i < stairs_count; i++)
    {
        pinMode(stairs_pins[i], OUTPUT);
    }
    state = st_wait;
}



//MAIN LOOP
void loop() 
{
    if (state == st_wait)
    {
        if (digitalRead(up_pir_pin) == HIGH) 
        {
            state = st_up;
        }
        if (digitalRead(down_pir_pin) == HIGH) 
        {
            state = st_down;
        }
        delay(check_delay);
    }
    else if (state == st_up)
    {
        for (int stair = stair; stair < stairs_count; stair++)
        {
            digitalWrite(stairs_pins[stair], HIGH);
            delay(light_delay);        
        }
        for (int stair = stair; stair < stairs_count; stair++)
        {
            digitalWrite(stairs_pins[stair], LOW); 
            delay(light_delay);
        }
        state = st_wait;
    } 
    else if (state == st_down)
    {
        for (int stair = stairs_count-1; stair >= 0; stair--)
        {
            digitalWrite(stairs_pins[stair], HIGH);
            delay(light_delay);
        }
        for (int stair = stairs_count-1; stair >= 0; stair--)
        {
            digitalWrite(stairs_pins[stair], LOW);     
            delay(light_delay);     
        }
        state = st_wait;
    }
}
