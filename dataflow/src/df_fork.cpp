#include "helper_fct.h"
#include "df_fork.h"

void DF_Fork::fork_value_thread() {

    DISPLAY("RUNNING THREAD");

    for(;;) {

        DISPLAY("DF_FORK : Wait for added_value ");
        double v1 = added_value->read();

        wait(10, SC_NS);

        DISPLAY("DF_FORK : added_value " << v1);

        feedback->write(v1);
        result->write(v1);

    }


}