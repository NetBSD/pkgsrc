$NetBSD: patch-mozilla_media_mtransport_third__party_nrappkit_src_log_r__log.c,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/mtransport/third_party/nrappkit/src/log/r_log.c.orig	2013-05-03 03:08:06.000000000 +0000
+++ mozilla/media/mtransport/third_party/nrappkit/src/log/r_log.c
@@ -48,6 +48,7 @@ static char *RCSSTRING __UNUSED__ ="$Id:
 #include "hex.h"
 
 #include <string.h>
+#include <errno.h>
 #ifndef _MSC_VER
 #include <strings.h>
 #include <syslog.h>
