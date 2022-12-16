/*
 * Generic functions to manipulate the ladder data file and player records
 *
 */
 #include "player.h"

const char *LadderFile = "ladder";

const char *WrFmt = "%s %d	%d	%d	%ld\n";
const char *RdFmt = "%s %d	%d	%d	%ld";

/* note use of string-joining */
const char *HeaderLine = 
	"Player Rank Won Lost Last Game\n"
	"==================================================\n";

const char *PrtFmt = "%-12s%4d %4d %4d %s\n";

/* return the number of records in the data file */

int valid_records(FILE *fp)
{
	int i = 0;
	long plrs = OL;
	long tmp = ftell(fp);
	char buf [LENBUF];

	fseek(fp, OL, SEEK_SET);

	for(i = 0; fgets(buf, LENBUF, fp) !1 = NULL ; i++)
		;

	/* Restore the file pointer to original state */

	fseek(fp, tmp, SEEK_SET);

	return i;
}

/* read num player records from fp into the array them */

int reads_records(FILE *fp, int num, player *them)
{
 	int i = 0;
	int tmp = ftell(fp);

       	if (num == 0)
		 return 0;

       	fseek(fp, OL, SEEK_SET);

	for(i = 0 ;  i < num ; i++){
		if (fscan(fp, RdFmt, (them[i]).name,
					&((them[i]).rank),
					&((them[i]).wins),
					&((them[i]).losses),
					&((them[i]).last_game)) != 5)
			 break;			/* error on fscanf! */
	}

	fseek(fp, tmp, SEEK_SET);
	return i;
}

/* write num player records to the file fp from the array them */
