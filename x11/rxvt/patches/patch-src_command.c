$NetBSD: patch-src_command.c,v 1.1 2017/08/05 07:00:20 nros Exp $
* fix CVE-2017-7483
--- src/command.c.orig	2017-08-05 06:35:48.000000000 +0000
+++ src/command.c
@@ -2096,7 +2096,7 @@ rxvt_process_csi_seq(rxvt_t *r)
     i = ch - CSI_ICH;
     ndef = get_byte_array_bit(csi_defaults, i);
     for (p = 0; p < nargs; p++)
-	if (arg[p] == -1)
+	if (arg[p] < 0 || arg[p] > 30000)
 	    arg[p] = ndef;
 
 #ifdef DEBUG_CMD
