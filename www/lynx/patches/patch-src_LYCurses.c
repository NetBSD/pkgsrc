$NetBSD: patch-src_LYCurses.c,v 1.3 2018/05/17 10:16:25 jperkin Exp $

Pull in upstream patch to fix build against newer ncurses.

--- src/LYCurses.c.orig	2014-03-09 21:43:10.000000000 +0000
+++ src/LYCurses.c
@@ -1695,7 +1695,7 @@ void lynx_enable_mouse(int state)
 void lynx_nl2crlf(int normal GCC_UNUSED)
 {
 #if defined(NCURSES_VERSION_PATCH) && defined(SET_TTY) && defined(TERMIOS) && defined(ONLCR)
-    static TTY saved_tty;
+    static struct termios saved_tty;
     static int did_save = FALSE;
     static int waiting = FALSE;
     static int can_fix = TRUE;
@@ -1704,8 +1704,10 @@ void lynx_nl2crlf(int normal GCC_UNUSED)
 	if (cur_term == 0) {
 	    can_fix = FALSE;
 	} else {
-	    saved_tty = cur_term->Nttyb;
+	    tcgetattr(fileno(stdout), &saved_tty);
 	    did_save = TRUE;
+	    if ((saved_tty.c_oflag & ONLCR))
+		can_fix = FALSE;
 #if NCURSES_VERSION_PATCH < 20010529
 	    /* workaround for optimizer bug with nonl() */
 	    if ((tigetstr("cud1") != 0 && *tigetstr("cud1") == '\n')
@@ -1717,14 +1719,18 @@ void lynx_nl2crlf(int normal GCC_UNUSED)
     if (can_fix) {
 	if (normal) {
 	    if (!waiting) {
-		cur_term->Nttyb.c_oflag |= ONLCR;
+		struct termios alter_tty = saved_tty;
+
+		alter_tty.c_oflag |= ONLCR;
+		tcsetattr(fileno(stdout), TCSAFLUSH, &alter_tty);
+		def_prog_mode();
 		waiting = TRUE;
 		nonl();
 	    }
 	} else {
 	    if (waiting) {
-		cur_term->Nttyb = saved_tty;
-		SET_TTY(fileno(stdout), &saved_tty);
+		tcsetattr(fileno(stdout), TCSAFLUSH, &saved_tty);
+		def_prog_mode();
 		waiting = FALSE;
 		nl();
 		LYrefresh();
