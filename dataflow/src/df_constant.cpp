#include "helper_fct.h"
#include "df_constant.h"


void DF_Constant::send_value_thread() {
    for(;;) {
        DISPLAY("SEND DATA");
        wait(1, SC_MS);
        const_value.write(cste);
        DISPLAY(" Send const_value : " << cste);
    }
}