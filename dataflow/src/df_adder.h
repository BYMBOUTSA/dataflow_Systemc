#ifndef DF_ADDER_H_
#define DF_ADDER_H_

#include <systemc.h>
#include "helper_fct.h"


SC_MODULE(DF_Adder) {

    // DECLARATION
    sc_fifo_in<double> feedback;
    sc_fifo_in<double> const_value;
    sc_fifo_out<double> added_value;


    // DATAS


    // CONSTRUCTOR
    SC_CTOR(DF_Adder) : feedback("feedback"),
                        const_value("const_value"),
                        added_value("added_value")
    {
        // REGISTATING THREAD
        // SAVE THREAD
        SC_THREAD(add_value_thread);
    }

    // PROCESS
    void add_value_thread();

};


#endif