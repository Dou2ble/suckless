/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 12;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "Arimo Nerd Font:size=10" };
static const char dmenufont[]       = "Arimo Nerd Font:size=10";

static const char col_gray1[]       = "#2C2E34";
static const char col_gray2[]       = "#33353F";
static const char col_gray3[]       = "#E2E2E3";
static const char col_gray4[]       = "#181819";
static const char col_gray5[]       = "#FC5D7C";
static const char col_cyan[]        = "#E39660";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan},
};


/* tagging */
static const char *tags[] = { "", "", "", "", "󰙯", "󰺄", "", "", "", "" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    { "Gimp",     NULL,       NULL,       0,            1,           -1 },
    { "Emacs",    NULL,       NULL,       1,            0,           -1 },
    { "Chromium", NULL,       NULL,       1 << 1,       0,           -1 },
    { "LibreWolf",NULL,       NULL,       1 << 1,       0,           -1 },
    { "discord",  NULL,       NULL,       1 << 4,       0,           -1 },
    { "okular",   NULL,       NULL,       1 << 5,       0,           -1 },
    { "thunderbird",NULL,     NULL,       1 << 6,       0,           -1 },
    { "firefox",  NULL,       NULL,       1 << 7,       0,           -1 },
    { "KeePassXC",NULL,       NULL,       1 << 8,       0,           -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "",      tile },    /* first entry is default */
    { "",      NULL },    /* no layout function means floating behavior */
    { "[󰟢]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


// /* commands */
// static const char *dmenucmd[] = { "sh", "-c", "source \"${HOME}/.cache/wal/colors.sh\"; dmenu_run -c -l 25 -nb \"$color0\" -nf \"$color15\" -sb \"$color1\" -sf \"$color15\"", NULL };
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *termexcmd[]  = { "tabbed", "-r", "2", "st", "-w", "", NULL };
static const char *browsercmd[]  = { "librewolf", NULL };
static const char *emacscmd[]  = { "emacs", NULL };
static const char *lockcmd[] = { "slock", NULL };

static const char *mancmd[]  = { "sh", "-c", "~/Scripts/man.sh", NULL };
static const char *doccmd[]  = { "sh", "-c", "~/Scripts/documents.sh", NULL };


static const Key keys[] = {
    /* modifier                     key        function        argument */
    { ALTKEY,                       XK_t,      spawn,          {.v = termcmd } },
    { ALTKEY|ShiftMask,             XK_t,      spawn,          {.v = termexcmd } },
    { ALTKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
    { ALTKEY,                       XK_b,      spawn,          {.v = browsercmd } },
    { ALTKEY,                       XK_e,      spawn,          {.v = emacscmd } },
    { ALTKEY,                       XK_l,      spawn,          {.v = lockcmd } },
    { ALTKEY|ShiftMask,             XK_m,      spawn,          {.v = mancmd } },
    { ALTKEY|ShiftMask,             XK_d,      spawn,          {.v = doccmd } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

