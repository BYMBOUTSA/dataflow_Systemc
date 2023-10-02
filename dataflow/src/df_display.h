#ifndef DF_DISPLAY_H_
#define DF_DISLAY_H_


#include <systemc.h>
#include "helper_fct.h"


SC_MODULE(DF_Display) {

    // DECLARATIONS
    sc_fifo_in<double> result;
    const double N;


    // DATAS

    SC_HAS_PROCESS(DF_Display);

    // CONSTRUCTOR
    DF_Display(sc_module_name name, const double n) : sc_module(name),
                                                      N(n),
                                                      result("result")
                                                      
    {
            // REGISTATING THREAD
            // SAVING THREAD
            SC_THREAD(display_value_thread);
    }           

    // PROCESS
    void display_value_thread();

};

#endif