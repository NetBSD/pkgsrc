$NetBSD: patch-media_mtransport_third__party_nrappkit_src_util_util.c,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/mtransport/third_party/nrappkit/src/util/util.c.orig	2013-05-11 19:19:43.000000000 +0000
+++ media/mtransport/third_party/nrappkit/src/util/util.c
@@ -45,6 +45,7 @@ static char *RCSSTRING __UNUSED__ ="$Id:
 #include <dirent.h>
 #endif
 #include <string.h>
+#include <errno.h>
 #include <ctype.h>
 #include <sys/stat.h>
 #ifdef OPENSSL
