$NetBSD: patch-src_mod__dnssd.c,v 1.1 2015/01/04 05:58:35 obache Exp $

* Apache 2.4 API change

--- src/mod_dnssd.c.orig	2009-01-28 02:24:00.000000000 +0000
+++ src/mod_dnssd.c
@@ -26,6 +26,9 @@
 #include <unixd.h>
 #include <apr_signal.h>
 #include <mpm_common.h>
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20090130
+#include "mod_unixd.h"
+#endif
 
 #include <unistd.h>
 
@@ -576,7 +579,11 @@ static void child_process(apr_pool_t *p,
 
     ap_assert(d);
 
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20090130
+    ap_unixd_setup_child();
+#else
     unixd_setup_child();
+#endif
 
     if (pipe(sigterm_pipe_fds) < 0) {
         ap_log_error(APLOG_MARK, APLOG_ERR, 0, r.main_server, "pipe() failed: %s", strerror(errno));
