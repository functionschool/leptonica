/*====================================================================*
 -  Copyright (C) 2001 Leptonica.  All rights reserved.
 -  This software is distributed in the hope that it will be
 -  useful, but with NO WARRANTY OF ANY KIND.
 -  No author or distributor accepts responsibility to anyone for the
 -  consequences of using this software, or for whether it serves any
 -  particular purpose or works at all, unless he or she says so in
 -  writing.  Everyone is granted permission to copy, modify and
 -  redistribute this source code, for commercial or non-commercial
 -  purposes, with the following restrictions: (1) the origin of this
 -  source code must not be misrepresented; (2) modified versions must
 -  be plainly marked as such; and (3) this notice may not be removed
 -  or altered from any source or modified source distribution.
 *====================================================================*/

/*
 * morphseqtest.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "allheaders.h"

#define  VALID_SEQUENCE   "O1.3 + C3.1 + R22 + D2.2 + X4"
#define  BAD_SEQUENCE     "O1.+D8 + E2.4 + e.4 + r25 + R + R.5 + X "\
                          " + x5 + y7.3"


main(int    argc,
     char **argv)
{
char        *infile;
PIX         *pixs, *pixd;
static char  mainName[] = "morphseqtest";

    if (argc != 2)
	exit(ERROR_INT(" Syntax:  morphseqtest infile", mainName, 1));

    infile = argv[1];
    pixs = pixRead(infile);

    fprintf(stderr, "Valid sequence: %s:\n", VALID_SEQUENCE);
    pixd = pixMorphSequence(pixs, VALID_SEQUENCE, 250);
    pixWrite("junkpixd", pixd, IFF_PNG);
    pixDestroy(&pixd);

    fprintf(stderr, "\nBad sequence: %s:\n", BAD_SEQUENCE);
    pixd = pixMorphSequence(pixs, BAD_SEQUENCE, 50);
    pixDestroy(&pixd);

    pixDestroy(&pixs);
    exit(0);
}

