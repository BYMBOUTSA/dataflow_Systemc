#include "df_adder.h"
#include "helper_fct.h"

void DF_Adder::add_value_thread() {
    for(;;) {
        DISPLAY("DF_Adder : Wait for reading const_value");
        double v1 = const_value.read();

        DISPLAY("DF_Adder : Wait for reading feedback");
        double v2 = feedback.read();

        wait(100, SC_NS);
        DISPLAY("DF_Adder " <<  v1 << " + " << v2 << " = " << v1 + v2);
        added_value->write(v1 + v2);

    }

}