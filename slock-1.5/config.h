/* user and group to drop privileges to */
static const char *user  = "otto";
static const char *group = "otto";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#2C2E34",     /* after initialization */
	[INPUT] =  "#F39660",   /* during input */
	[FAILED] = "#FC5D7C",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;
