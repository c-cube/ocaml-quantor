/*
Copyright (c) 2003 - 2014 Armin Biere, ETH Zurich, JKU Linz.

All rights reserved. Redistribution and use in source and binary forms, with
or without modification, are permitted provided that the following
conditions are met:

  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.

  3. All advertising materials mentioning features or use of this software
     must display the following acknowledgement:

	  This product includes software developed by 
	  Armin Biere, Johannes Kepler University, Linz, Austria.

  4. Neither the name of the University nor the names of its contributors
     may be used to endorse or promote products derived from this software
     without specific prior written permission.
   
THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "config.h"

/*------------------------------------------------------------------------*/

#include "quantor.h"

/*------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

/*------------------------------------------------------------------------*/
#ifdef QUANTOR_QBF_EVALUATION_FORMAT
/*------------------------------------------------------------------------*/

static char *my_argv[5];
static char buffer[100];

/*------------------------------------------------------------------------*/
#endif
/*------------------------------------------------------------------------*/
/* We provide a dummy 'checkapi' here to break the dependency of 'quantor'
 * on 'checkapi.c'.
 */
void
checkapi (FILE * dummy_file, int dummy_test_case_number)
{
  (void) dummy_file;
  (void) dummy_test_case_number;
}

/*------------------------------------------------------------------------*/

int
main (int argc, char **argv)
{
#ifdef QUANTOR_QBF_EVALUATION_FORMAT
  double time_limit;
  if (argc != 3)
    {
      fprintf (stderr,
	       "*** usage of quantor compiled for SAT04 QBF:\n"
	       "*** quantor <file.qdimacs> <time-limit>\n");
      exit (1);
    }

  my_argv[0] = argv[0];
  my_argv[1] = argv[1];
  time_limit = atof (argv[2]);
  sprintf (buffer, "--time-limit=%.1f", time_limit);
  my_argv[2] = buffer;
  my_argv[3] = "--fast-exit";
  my_argv[4] = "--verbose=2";
  return quantor_main (5, my_argv);
#else
  return quantor_main (argc, argv);
#endif
}
