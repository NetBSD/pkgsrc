$NetBSD: patch-lib_sigpipe.h,v 1.1 2024/08/25 06:06:00 wiz Exp $

sigpipe: init the struct so that first apply ignores #14390 
https://github.com/curl/curl/pull/14390/files

--- lib/sigpipe.h.orig	2024-07-31 06:51:53.000000000 +0000
+++ lib/sigpipe.h
@@ -39,6 +39,7 @@ struct sigpipe_ignore {
 static void sigpipe_init(struct sigpipe_ignore *ig)
 {
   memset(ig, 0, sizeof(*ig));
+  ig->no_signal = TRUE;
 }
 
 /*
