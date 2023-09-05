//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
{"🔊", "amixer get Master | egrep -o '[0-9]{1,3}%'",	                 1,		0},

	{"🔋", "cat /sys/class/power_supply/BAT0/capacity",	30,		0},

	{"", "date '+%b %d (%a) %H:%M'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

