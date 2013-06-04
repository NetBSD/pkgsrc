$NetBSD: patch-include_ap__config.h,v 1.1 2013/06/04 22:08:20 fhajny Exp $

Non-existent DTrace support from upstream is not a reason to break
3rd party DTrace enabled modules. This patch should be removed
when DTrace support is actually implemented upstream (and working).

--- include/ap_config.h.orig	2012-08-14 23:59:24.000000000 +0000
+++ include/ap_config.h
@@ -148,17 +148,7 @@
 #define AP_NONBLOCK_WHEN_MULTI_LISTEN 1
 #endif
 
-#if defined(AP_ENABLE_DTRACE) && HAVE_SYS_SDT_H
-#include <sys/sdt.h>
-#else
-#undef _DTRACE_VERSION
-#endif
-
-#ifdef _DTRACE_VERSION
-#include "apache_probes.h"
-#else
 #include "apache_noprobes.h"
-#endif
 
 /* If APR has OTHER_CHILD logic, use reliable piped logs. */
 #if APR_HAS_OTHER_CHILD
