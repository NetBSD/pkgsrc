$NetBSD: patch-WWW_Library_Implementation_HTTP.c,v 1.4 2021/08/12 04:20:11 kim Exp $

Address CVE-2021-38165 [From 2021-08-07 (2.9.0dev.9)]:

* strip user/password from ssl_host in HTLoadHTTP, incorrectly passed as
  part of the server name indicator (Debian #991971) -TD

Index: WWW/Library/Implementation/HTTP.c
--- WWW/Library/Implementation/HTTP.c	2021-06-08 23:28:23.000000000 +0000
+++ WWW/Library/Implementation/HTTP.c	2021-08-07 14:33:59.000000000 +0000
@@ -764,6 +764,23 @@
 }
 #endif
 
+/*
+ * Remove user/password, if any, from the given host-string.
+ */
+#ifdef USE_SSL
+static char *StripUserAuthents(char *host)
+{
+    char *p = strchr(host, '@');
+
+    if (p != NULL) {
+	char *q = host;
+
+	while ((*q++ = *++p) != '\0') ;
+    }
+    return host;
+}
+#endif
+
 /*		Load Document from HTTP Server			HTLoadHTTP()
  *		==============================
  *
@@ -959,6 +976,7 @@
 	/* get host we're connecting to */
 	ssl_host = HTParse(url, "", PARSE_HOST);
 	ssl_host = StripIpv6Brackets(ssl_host);
+	ssl_host = StripUserAuthents(ssl_host);
 #if defined(USE_GNUTLS_FUNCS)
 	ret = gnutls_server_name_set(handle->gnutls_state,
 				     GNUTLS_NAME_DNS,
