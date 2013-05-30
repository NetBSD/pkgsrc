$NetBSD: patch-modules_mappers_mod_rewrite.c,v 1.3 2013/05/30 22:58:15 tron Exp $

Fix for security vulnerability reported in CVE-2013-1862. Patch taken
from here:

http://people.apache.org/~jorton/mod_rewrite-CVE-2013-1862.patch

--- modules/mappers/mod_rewrite.c.orig	2013-02-18 21:31:42.000000000 +0000
+++ modules/mappers/mod_rewrite.c	2013-05-30 23:50:27.000000000 +0100
@@ -500,11 +500,11 @@
 
     logline = apr_psprintf(r->pool, "%s %s %s %s [%s/sid#%pp][rid#%pp/%s%s%s] "
                                     "(%d) %s%s%s%s" APR_EOL_STR,
-                           rhost ? rhost : "UNKNOWN-HOST",
-                           rname ? rname : "-",
-                           r->user ? (*r->user ? r->user : "\"\"") : "-",
+                           rhost ? ap_escape_logitem(r->pool, rhost) : "UNKNOWN-HOST",
+                           rname ? ap_escape_logitem(r->pool, rname) : "-",
+                           r->user ? (*r->user ? ap_escape_logitem(r->pool, r->user) : "\"\"") : "-",
                            current_logtime(r),
-                           ap_get_server_name(r),
+                           ap_escape_logitem(r->pool, ap_get_server_name(r)),
                            (void *)(r->server),
                            (void *)r,
                            r->main ? "subreq" : "initial",
@@ -514,7 +514,7 @@
                            perdir ? "[perdir " : "",
                            perdir ? perdir : "",
                            perdir ? "] ": "",
-                           text);
+                           ap_escape_logitem(r->pool, text));
 
     nbytes = strlen(logline);
     apr_file_write(conf->rewritelogfp, logline, &nbytes);
