$NetBSD: patch-src_term.c,v 1.1 2021/09/19 08:49:01 nia Exp $

Add patch from rxvt-unicode to fix CVE-2021-33477.
https://sources.debian.org/patches/eterm/0.9.6-6.1/CVE-2021-33477.patch/

--- src/term.c.orig	2011-03-16 05:16:59.000000000 +0000
+++ src/term.c
@@ -1176,6 +1176,7 @@ process_escape_seq(void)
         case 'E':
             scr_add_lines((unsigned char *) "\n\r", 1, 2);
             break;
+#if 0 /* disabled because embedded newlines can make exploits easier */
         case 'G':
             if ((ch = cmd_getc()) == 'Q') {     /* query graphics */
                 tt_printf((unsigned char *) "\033G0\n");        /* no graphics */
@@ -1185,6 +1186,7 @@ process_escape_seq(void)
                 } while (ch != ':');
             }
             break;
+#endif
         case 'H':
             scr_set_tab(1);
             break;
