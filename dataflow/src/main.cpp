/****************************************************************************
 * Copyright (C) 2021 by Fabrice Muller                                     *
 *                                                                          *
 * This file is useful for SystemC course.                             *
 *                                                                          *
 ****************************************************************************/

/**
 * @file main.c
 * @author Fabrice Muller
 * @date 02 Nov. 2021
 * @brief Empty main program for SystemC
 *
 * @see https://github.com/fmuller-pns/systemc-vscode-project-template.git
 */

#include <systemc.h>
#include "helper_fct.h"
#include "df_constant.h"
#include "df_adder.h"
#include "df_fork.h"


int sc_main(int argc, char* argv[]) {

	// DECLARATION
	sc_fifo<double> const_value_fifo("const_value", 20);
	sc_fifo<double> feedback_fifo;
	sc_fifo<double> added_value_fifo;
	sc_fifo<double> result_fifo;

	/* Elaboration step */
	DISPLAY("ELABORATION");

	// Instantiation and port map
	DF_Constant DF_Constant_inst("DF_Constant_inst", 5.2);
	            DF_Constant_inst.const_value(const_value_fifo);
	
	DF_Adder DF_Adder_inst("DF_Adder_inst");
			 DF_Adder_inst.const_value(const_value_fifo);
			 DF_Adder_inst.feedback(feedback_fifo);
			 DF_Adder_inst.added_value(added_value_fifo);


	DF_Fork DF_Fork_inst("DF_Fork_inst");
	        DF_Fork_inst.added_value(added_value_fifo);
			DF_Fork_inst.feedback(feedback_fifo);
			DF_Fork_inst.result(result_fifo);


	/* Simulation step */
	DISPLAY("START SIMULATION");

	sc_start(10, SC_MS);
	feedback_fifo.write(2.3);
	feedback_fifo.write(4.2);
	feedback_fifo.write(6.7);

	sc_start(350, SC_MS);

	/* End of Simulation */
	DISPLAY("END OF SIMULATION");
				
	return 0;
}


