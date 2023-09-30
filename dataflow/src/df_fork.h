#ifndef DF_FORK_H_
#define DF_FORK_H_

#include <systemc.h>
#include "helper_fct.h"

SC_MODULE(DF_Fork) {

    // DECLARATIONS
    sc_fifo_in<double> added_value;
    sc_fifo_out<double> feedback;
    sc_fifo_out<double> result;     

    // DATAS

    // CONSTRUCTOR
    SC_CTOR(DF_Fork) : added_value("added_value"),
                       feedback("feedback"),
                       result("result")     
    {
        // REGISTATING THREAD
        // SAVE THREAD
        SC_THREAD(fork_value_thread);
    }

    // PROCESS
    void fork_value_thread();

};

#endif
