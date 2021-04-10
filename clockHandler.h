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