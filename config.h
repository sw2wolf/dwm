static void runorraise(const Arg *arg);
static void restart(const Arg * arg);
static void togglefullscreen(const Arg *arg);

//static const char font[] = "-*-simsun-medium-r-normal-*-12-*-*-*-*-*-iso10646-1";
static const char font[] = "Sans:size=11";

static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#005577";
static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
//static const Bool showbar           = False;     /* False means no bar */
//static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3" };

static const Rule rules[] = {
	/* class      instance    title     tags mask     isfloating   monitor */
    /* { "Emacs",    NULL,       NULL,     0,            True,        -1 }, */
    /* {"Gimp", NULL, NULL, 0, True, -1}, */
	/* {"VirtualBox", NULL, NULL, 0, True, -1}, */
	/* {"QEMU", NULL, NULL, 0, True, -1}, */
	{ "Wine",     NULL,       NULL,     1 << 1,       True,        -1 },
};

/* layout(s) */
//static const float mfact      = 0.45; /* factor of master area size [0.05..0.95] */
//static const int nmaster      = 1;    /* number of clients in master area */
//static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

/* first entry is default */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	/* { "[]=",      tile }, */
	/* { "[M]",      monocle }, */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },
/* { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, */
/* { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenu[] = { "/home/sw2wolf/bin/dmenu.sh", NULL };
static const char *sdcv[] =  { "/home/sw2wolf/bin/sdcv.sh", NULL };
static const char *eval[] = { "/home/sw2wolf/bin/clisp.sh", NULL };

static const char *www[] = { "firefox", NULL, NULL, NULL, "Firefox"};
/* static const char *www[] = { "luakit", NULL, NULL, NULL, "luakit"}; */
static const char *term[] = { "xterm", NULL, NULL, NULL, "XTerm"};

static const char *emacs[] = { "emacs", NULL, NULL, NULL, "Emacs"};
//static const char *winxp[] = { "VBoxManage", "startvm", "winxp", NULL, "VirtualBox"};

//static const char *eweiqi[] = { "wine", "c:/Program Files/eweiqi/LiveBaduk.exe", NULL};

static Key keys[] = {
	/* modifier     key        function        argument */
    { MODKEY,       XK_w,      runorraise,     {.v = www } },
	{ MODKEY,       XK_e,      runorraise,     {.v = emacs } },
    { MODKEY,       XK_t,      runorraise,     {.v = term } },

    { MODKEY,       XK_p,      spawn,          {.v = dmenu } },
    { MODKEY,       XK_c,      spawn,          {.v = sdcv } },
    { MODKEY,       XK_x,      spawn,          {.v = eval } },

	//{ MODKEY|ShiftMask,      XK_x,      spawn,          {.v = winxp } },
	//{ MODKEY|ShiftMask,      XK_g,      spawn,          {.v = eweiqi } },
//
	{ MODKEY,      XK_F11,    spawn,          SHCMD("sudo /sbin/shutdown -r now") },
	{ MODKEY,      XK_F12,    spawn,          SHCMD("sudo /sbin/shutdown -ph now") },
//
//	{ MODKEY,      XK_b,      togglebar,      {0} },

	{ MODKEY,      XK_Tab,    focusstack,     {.i = +1 } },
	{ MODKEY,      XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,      XK_k,      focusstack,     {.i = -1 } },

//	{ MODKEY,      XK_i,      incnmaster,     {.i = +1 } },
//	{ MODKEY,      XK_d,      incnmaster,     {.i = -1 } },
//	{ MODKEY,      XK_h,      setmfact,       {.f = -0.05} },
//	{ MODKEY,      XK_l,      setmfact,       {.f = +0.05} },
//	{ MODKEY,                       XK_Return, zoom,           {0} },
//	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
//	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[0]} },
//	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[1]} },
//	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
//	{ MODKEY,                       XK_space,  setlayout,      {0} },
//	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefullscreen, {0} },
//	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
//	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
//	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
//	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	{ MODKEY|ShiftMask,             XK_r,      restart,        {0} },   // restart
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },   // logout
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click           event mask      button          function        argument */
//{ ClkLtSymbol,       0,              Button1,        setlayout,      {0} },
//{ ClkLtSymbol,       0,              Button3,        setlayout,      {.v = &layouts[2]} },
//{ ClkWinTitle,       0,              Button2,        zoom,           {0} },
	{ ClkClientWin,    MODKEY,         Button1,        movemouse,      {0} },
//	{ ClkClientWin,    MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,    MODKEY,         Button3,        resizemouse,    {0} },
//	{ ClkTagBar,       0,              Button1,        view,           {0} },
//  { ClkTagBar,       0,              Button3,        toggleview,     {0} },
//	{ ClkTagBar,       MODKEY,         Button1,        tag,            {0} },
//	{ ClkTagBar,       MODKEY,         Button3,        toggletag,      {0} },
};

void
runorraise(const Arg *arg) {
	const char **app = (const char **)arg->v;
	Arg a = { .ui = ~0 };
	Client *c;
	Monitor *mon;
	XClassHint hint = { NULL, NULL };
	
	for (mon = mons; mon; mon = mon->next) {
		for (c = mon->clients; c; c = c->next) {
			XGetClassHint(dpy, c->win, &hint);
			if (hint.res_class && strcmp(app[4], hint.res_class) == 0) {
				a.ui = c->tags;
				view(&a);
				focus(c);
				XRaiseWindow(dpy, c->win);
				return ;
			}
		}
	}

	spawn(arg);
}

void
togglefullscreen(const Arg *arg) {
	Client *c = selmon->sel;

	if(!c)
		return;
	setfullscreen(c, !c->isfullscreen);
}

void
restart(const Arg * arg)
{
	if (arg->v) {
		execvp(((char **) arg->v)[0], (char **) arg->v);
	} else {
		execlp("dwm", "dwm", NULL);
	}
}

/* void */
/* togglelayout(const Arg * arg) */
/* { */
/* 	Arg a; */

/* 	if (selmon->lt[selmon->sellt] == &layouts[0]) { */
/* 		a.v = arg->v; */
/* 	} else { */
/* 		a.v = &layouts[0]; */
/* 	} */
/* 	setlayout(&a); */
/* } */

/*
 * This is all I have to do to lock the screen.  See http://woozle.org/~neale/src/xss/ 
 */
/* void */
/* screensave(const Arg * arg) */
/* { */
/* 	XActivateScreenSaver(dpy); */
/* } */

/* void */
/* multimedia(const Arg * arg) */
/* { */
/* 	Arg a; */

/* 	a.v = (const char *[]) { */
/* 	"mm", (char *) arg->v, NULL}; */
/* 	spawn(&a); */
/* } */

/* *******
 * Patches
 * ********/

/* grid layout */
// http://dwm.suckless.org/patches/gridmode
// from 5.8.2 diff+
//#include "/etc/portage/savedconfig/x11-wm/dwm-5.8.2-gridmode.c"

/* bottom stack layouts */
// http://dwm.suckless.org/patches/bottom_stack
// from source for 5.9
//#include "/etc/portage/savedconfig/x11-wm/dwm-5.9-bstack.c"

/* push patch */
// http://dwm.suckless.org/patches/push
// from patch for 5.7.1
//#include "/etc/portage/savedconfig/x11-wm/dwm-5.7.1-push.c"
