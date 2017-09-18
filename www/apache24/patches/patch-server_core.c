$NetBSD: patch-server_core.c,v 1.2 2017/09/18 13:34:51 wiz Exp $

Fix security problem using upstream patch.
http://svn.apache.org/viewvc/httpd/httpd/branches/2.4.x/server/core.c?r1=1805223&r2=1807754&pathrev=1807754&view=patch

--- server/core.c.orig	2016-12-05 14:34:29.000000000 +0000
+++ server/core.c
@@ -2262,6 +2262,12 @@ AP_CORE_DECLARE_NONSTD(const char *) ap_
             /* method has not been registered yet, but resource restriction
              * is always checked before method handling, so register it.
              */
+            if (cmd->pool == cmd->temp_pool) {
+                /* In .htaccess, we can't globally register new methods. */
+                return apr_psprintf(cmd->pool, "Could not register method '%s' "
+                                   "for %s from .htaccess configuration",
+                                    method, cmd->cmd->name);
+            }
             methnum = ap_method_register(cmd->pool,
                                          apr_pstrdup(cmd->pool, method));
         }
