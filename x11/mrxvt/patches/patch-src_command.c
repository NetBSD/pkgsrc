$NetBSD: patch-src_command.c,v 1.1 2017/11/27 08:05:24 maya Exp $

Avoid integer overflow (CVE-2017-7483)

--- src/command.c.orig	2008-07-09 21:33:36.000000000 +0000
+++ src/command.c
@@ -5207,7 +5207,7 @@ rxvt_process_csi_seq(rxvt_t* r, int page
     i = ch - CSI_ICH;
     ndef = get_byte_array_bit(csi_defaults, i);
     for (p = 0; p < nargs; p++)
-	if (arg[p] == -1)
+	if (arg[p] < 0 || arg[p] > 30000)
 	    arg[p] = ndef;
 
 #ifdef DEBUG
