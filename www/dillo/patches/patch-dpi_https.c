$NetBSD: patch-dpi_https.c,v 1.1 2018/03/24 15:40:07 ryoon Exp $

* Support OpenSSL 1.1.0

--- dpi/https.c.orig	2015-06-30 14:06:08.000000000 +0000
+++ dpi/https.c
@@ -476,7 +476,11 @@ static int handle_certificate_problem(SS
       case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
          /*Either self signed and untrusted*/
          /*Extract CN from certificate name information*/
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
          if ((cn = strstr(remote_cert->name, "/CN=")) == NULL) {
+#else
+         if ((cn = strstr(X509_get_subject_name(remote_cert), "/CN=")) == NULL) {
+#endif
             strcpy(buf, "(no CN given)");
          } else {
             char *cn_end;
