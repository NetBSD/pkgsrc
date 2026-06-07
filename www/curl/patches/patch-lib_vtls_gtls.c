$NetBSD: patch-lib_vtls_gtls.c,v 1.1 2026/06/07 18:03:46 adam Exp $

Allow building with nettle 4.0
https://github.com/curl/curl/pull/21169

--- lib/vtls/gtls.c.orig	2026-04-29 05:45:57.000000000 +0000
+++ lib/vtls/gtls.c
@@ -37,6 +37,7 @@
 #include <gnutls/x509.h>
 #include <gnutls/crypto.h>
 #include <nettle/sha2.h>
+#include <nettle/version.h>
 
 #include "urldata.h"
 #include "curl_trc.h"
@@ -2261,7 +2262,11 @@ static CURLcode gtls_sha256sum(const uns
   struct sha256_ctx SHA256pw;
   sha256_init(&SHA256pw);
   sha256_update(&SHA256pw, (unsigned int)tmplen, tmp);
+#if NETTLE_VERSION_MAJOR >= 4
+  sha256_digest(&SHA256pw, sha256sum);
+#else
   sha256_digest(&SHA256pw, (unsigned int)sha256len, sha256sum);
+#endif
   return CURLE_OK;
 }
 
