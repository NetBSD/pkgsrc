$NetBSD: patch-os_rpcauth.c,v 1.1 2023/03/30 08:45:06 wiz Exp $

Ugly hack - NetBSD doesn't provide 'struct authdes_cred'.

--- os/rpcauth.c.orig	2023-03-29 12:26:36.000000000 +0000
+++ os/rpcauth.c
@@ -106,7 +106,11 @@ authdes_ezdecode(const char *inmsg, int 
 #endif
         goto bad2;
     }
+#ifdef __NetBSD__
+    return NULL;
+#else
     return (((struct authdes_cred *) r.rq_clntcred)->adc_fullname.name);
+#endif
 
  bad2:
     free(r.rq_clntcred);
