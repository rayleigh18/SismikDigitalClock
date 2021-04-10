unsigned int sec_clock = 0;
unsigned int min_clock = 0;
unsigned int hour_clock = 0;
unsigned int day_clock = 0;

// called every 1 second
void clockHandler(){
    sec_clock++;
    if (sec_clock == 60){
        min_clock += 1;
        sec_clock = 0;
    }

    if (min_clock == 60){
        hour_clock+= 1;
        min_clock = 0;
    }

    if (hour_clock == 24){
        day_clock += 1;
        hour_clock = 0;
    }
}


void setupTimerButton(){
    cli();
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1  = 0;
    // set compare match register for 1hz increments
    OCR1A = 15624;
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS12) | (1 << CS10);  // 1024 
    TIMSK1 |= (1 << OCIE1A);
    sei();
}

ISR(TIMER1_COMPA_vect){
    clockHandler();
}