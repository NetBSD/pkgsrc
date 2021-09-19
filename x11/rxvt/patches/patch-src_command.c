$NetBSD: patch-src_command.c,v 1.2 2021/09/19 08:41:13 nia Exp $

* fix CVE-2021-33477
* fix CVE-2017-7483

--- src/command.c.orig	2003-03-26 06:01:23.000000000 +0000
+++ src/command.c
@@ -1954,10 +1954,12 @@ rxvt_process_escape_seq(rxvt_t *r)
 	rxvt_scr_add_lines(r, (const unsigned char *)"\n\r", 1, 2);
 	break;
 
+#if 0 /* disabled because embedded newlines can make exploits easier */
     /* kidnapped escape sequence: Should be 8.3.48 */
     case C1_ESA:		/* ESC G */
 	rxvt_process_graphics(r);
 	break;
+#endif
 
     /* 8.3.63: CHARACTER TABULATION SET */
     case C1_HTS:		/* ESC H */
@@ -2096,7 +2098,7 @@ rxvt_process_csi_seq(rxvt_t *r)
     i = ch - CSI_ICH;
     ndef = get_byte_array_bit(csi_defaults, i);
     for (p = 0; p < nargs; p++)
-	if (arg[p] == -1)
+	if (arg[p] < 0 || arg[p] > 30000)
 	    arg[p] = ndef;
 
 #ifdef DEBUG_CMD
