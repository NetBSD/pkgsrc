$NetBSD: patch-src_mod__auth__gssapi.h,v 1.1 2026/05/16 03:47:29 riastradh Exp $

Use <gssapi/gssapi_ext.h> conditionally: mit-krb5 has it, heimdal does
not (even newer versions with the GSSAPI extensions).

--- src/mod_auth_gssapi.h.orig	2020-11-30 18:30:59.758815269 +0000
+++ src/mod_auth_gssapi.h
@@ -30,7 +30,9 @@
 #include "config.h"
 
 #include <gssapi/gssapi.h>
+#ifdef HAVE_GSSAPI_GSSAPI_EXT_H
 #include <gssapi/gssapi_ext.h>
+#endif
 #include <gssapi/gssapi_krb5.h>
 #ifdef HAVE_GSSAPI_GSSAPI_NTLMSSP_H
 #  include <gssapi/gssapi_ntlmssp.h>
