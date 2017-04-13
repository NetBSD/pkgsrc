$NetBSD: patch-include_ttyutils.h,v 1.2 2017/04/13 10:17:25 jperkin Exp $

Define values if missing.

--- include/ttyutils.h.orig	2016-11-02 12:57:31.535167960 +0000
+++ include/ttyutils.h
@@ -60,6 +60,18 @@ extern int get_terminal_name(const char
 static inline void reset_virtual_console(struct termios *tp, int flags)
 {
 	/* Use defaults of <sys/ttydefaults.h> for base settings */
+#ifndef TTYDEF_IFLAG
+#define TTYDEF_IFLAG	(BRKINT | ICRNL | IMAXBEL | IXON | IXANY)
+#endif
+#ifndef TTYDEF_OFLAG
+#define TTYDEF_OFLAG	(OPOST | ONLCR /*| OXTABS*/)
+#endif
+#ifndef TTYDEF_LFLAG
+#define TTYDEF_LFLAG	(ECHO | ICANON | ISIG | IEXTEN | ECHOE|ECHOKE|ECHOCTL)
+#endif
+#ifndef TTYDEF_CFLAG
+#define TTYDEF_CFLAG	(CREAD | CS8 | HUPCL)
+#endif
 	tp->c_iflag |= TTYDEF_IFLAG;
 	tp->c_oflag |= TTYDEF_OFLAG;
 	tp->c_lflag |= TTYDEF_LFLAG;
@@ -114,6 +126,13 @@ static inline void reset_virtual_console
 # define FFDLY 0
 #endif
 
+#ifndef TAB0
+#define TAB0 0
+#endif
+#ifndef TABDLY
+#define TABDLY 0
+#endif
+
 	tp->c_iflag |=  (BRKINT | ICRNL | IMAXBEL);
 	tp->c_iflag &= ~(IGNBRK | INLCR | IGNCR | IXOFF | IUCLC | IXANY | ISTRIP);
 	tp->c_oflag |=  (OPOST | ONLCR | NL0 | CR0 | TAB0 | BS0 | VT0 | FF0);
@@ -158,7 +177,13 @@ static inline void reset_virtual_console
 	tp->c_cc[VSTOP]    = CSTOP;
 	tp->c_cc[VSUSP]    = CSUSP;
 	tp->c_cc[VEOL]     = _POSIX_VDISABLE;
+#ifndef CREPRINT
+#define CREPRINT	('r' & 037)
+#endif
 	tp->c_cc[VREPRINT] = CREPRINT;
+#ifndef CDISCARD
+#define CDISCARD	('o' & 037)
+#endif
 	tp->c_cc[VDISCARD] = CDISCARD;
 	tp->c_cc[VWERASE]  = CWERASE;
 	tp->c_cc[VLNEXT]   = CLNEXT;
