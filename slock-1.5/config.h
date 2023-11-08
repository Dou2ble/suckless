/* user and group to drop privileges to */
static const char *user  = "otto";
static const char *group = "otto";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

/* default message */
static const char * message = "Suckless: Software that sucks less.";

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
// static const char * font_name = "Hack";
static const char * font_name = "-misc-hack nerd font-medium-r-normal--0-0-0-0-p-0-iso8859-16";
