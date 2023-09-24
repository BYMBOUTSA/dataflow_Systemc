#ifndef DF_CONSTANT_H
#define DF_CONSTANT_H

#include <systemc.h>
#include "helper_fct.h"

SC_MODULE(DF_Constant) {

    // DECLARATION
    sc_fifo_out<double> const_value;
    const double cste;


    // DATAS

    // Ajout de la macro pour utiliser le constructeur systemc 
    SC_HAS_PROCESS(DF_Constant);

    // CONSTRUCTOR with the MACRO
    DF_Constant(sc_module_name name, const double c) : sc_module(name),
                                                       cste(c),
                                                       const_value("const_value") 
    {
        // REGISTATING THREAD
        // SAVE THREAD
        SC_THREAD(send_value_thread);
    }

    // PROCESS
    void send_value_thread();

};


#endif