$NetBSD: patch-media_mtransport_third__party_nrappkit_src_log_r__log.c,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/mtransport/third_party/nrappkit/src/log/r_log.c.orig	2013-05-11 19:19:43.000000000 +0000
+++ media/mtransport/third_party/nrappkit/src/log/r_log.c
@@ -48,6 +48,7 @@ static char *RCSSTRING __UNUSED__ ="$Id:
 #include "hex.h"
 
 #include <string.h>
+#include <errno.h>
 #ifndef _MSC_VER
 #include <strings.h>
 #include <syslog.h>
