#include "df_display.h"
#include "helper_fct.h"


void DF_Display::display_value_thread() {

    for(int i = 0; i < N; i++) {
        // Read result FIFO
        double val = result->read();

        // Display
        DISPLAY("DF_Display : value = " << val);
    }

    DISPLAY("================= STOP DF_Display =================");

}

