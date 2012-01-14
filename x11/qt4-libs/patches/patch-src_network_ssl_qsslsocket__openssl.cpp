$NetBSD: patch-src_network_ssl_qsslsocket__openssl.cpp,v 1.1 2012/01/14 10:23:18 obache Exp $

* fix build with -openssl-linked for OpenSSL 0.9.8*
  http://qt.gitorious.org/qt/qt/commit/4db91cbd6147e40f543342f22c05b7baddc52e5a

--- src/network/ssl/qsslsocket_openssl.cpp.orig	2011-12-08 05:06:02.000000000 +0000
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -451,11 +451,7 @@ init_context:
         if (!ace.isEmpty()
             && !QHostAddress().setAddress(tlsHostName)
             && !(configuration.sslOptions & QSsl::SslOptionDisableServerNameIndication)) {
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
             if (!q_SSL_ctrl(ssl, SSL_CTRL_SET_TLSEXT_HOSTNAME, TLSEXT_NAMETYPE_host_name, ace.data()))
-#else
-            if (!q_SSL_ctrl(ssl, SSL_CTRL_SET_TLSEXT_HOSTNAME, TLSEXT_NAMETYPE_host_name, ace.constData()))
-#endif
                 qWarning("could not set SSL_CTRL_SET_TLSEXT_HOSTNAME, Server Name Indication disabled");
         }
     }
