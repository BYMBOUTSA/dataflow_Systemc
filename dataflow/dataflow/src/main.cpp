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


int sc_main(int argc, char* argv[]) {

	// DECLARATION
	sc_fifo<double> const_value_fifo("const_value", 20);


	/* Elaboration step */
	DISPLAY("ELABORATION");

	// Instantiation and port map
	DF_Constant DF_Constant_inst("DF_Constant_inst", 5.2);
	            DF_Constant_inst.const_value(const_value_fifo);
	



	/* Simulation step */
	DISPLAY("START SIMULATION");

	sc_start(350, SC_MS);

	/* End of Simulation */
	DISPLAY("END OF SIMULATION");
				
	return 0;
}


