/* user and group to drop privileges to */
static const char *user  = "otto";
static const char *group = "otto";

// gruvbox
static const char *colorname[NUMCOLS] = {
	[INIT] =   "#282828",   /* after initialization */
	[INPUT] =  "#458588",   /* during input */
	[FAILED] = "#cc241d",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

/* default message */
static const char * message = "Suckless: Software that sucks less.";

/* text color */
static const char * text_color = "#ebdbb2";

/* text size (must be a valid size) */
// static const char * font_name = "Hack";
static const char * font_name = "-misc-hack nerd font-medium-r-normal--0-0-0-0-p-0-iso8859-16";
