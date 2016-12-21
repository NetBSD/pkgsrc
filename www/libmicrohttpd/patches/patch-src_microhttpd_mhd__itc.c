$NetBSD: patch-src_microhttpd_mhd__itc.c,v 1.1 2016/12/21 10:31:42 wiz Exp $

commit 52e995c0a7741967ab68883a63a8c7e70a4589ee
Author: Evgeny Grin (Karlson2k) <k2k@narod.ru>
Date:   Fri Nov 11 13:24:30 2016 +0300

    mhd_itc.c: fixed typo preventing build on Solaris and other systems.

--- src/microhttpd/mhd_itc.c.orig	2016-10-15 12:37:00.000000000 +0000
+++ src/microhttpd/mhd_itc.c
@@ -58,7 +58,7 @@ MHD_itc_nonblocking_ (struct MHD_itc_ it
       return 0;
 
     if ( ((flags | O_NONBLOCK) != flags) &&
-         (0 != fcntl (pip.fd[i],
+         (0 != fcntl (itc.fd[i],
                       F_SETFL,
                       flags | O_NONBLOCK)) )
       return 0;
