$NetBSD: patch-src_ssl_support.cc,v 1.1 2025/01/27 11:39:15 wiz Exp $

Merge change from squid6 to fix build with openssl 3.

--- src/ssl/support.cc.orig	2021-10-03 17:18:09.000000000 +0000
+++ src/ssl/support.cc
@@ -396,7 +396,11 @@ Ssl::SetupVerifyCallback(Security::Conte
 }
 
 // "dup" function for SSL_get_ex_new_index("cert_err_check")
-#if SQUID_USE_CONST_CRYPTO_EX_DATA_DUP
+#if OPENSSL_VERSION_MAJOR >= 3
+static int
+ssl_dupAclChecklist(CRYPTO_EX_DATA *, const CRYPTO_EX_DATA *, void **,
+                    int, long, void *)
+#elif SQUID_USE_CONST_CRYPTO_EX_DATA_DUP
 static int
 ssl_dupAclChecklist(CRYPTO_EX_DATA *, const CRYPTO_EX_DATA *, void *,
                     int, long, void *)
@@ -485,23 +489,30 @@ Ssl::Initialize(void)
 
     SQUID_OPENSSL_init_ssl();
 
-#if !defined(OPENSSL_NO_ENGINE)
     if (::Config.SSL.ssl_engine) {
+#if OPENSSL_VERSION_MAJOR < 3
+        debugs(83, DBG_PARSE_NOTE(DBG_IMPORTANT), "WARNING: Support for ssl_engine is deprecated " <<
+               "in Squids built with OpenSSL 1.x (like this Squid). " <<
+               "It is removed in Squids built with OpenSSL 3.0 or newer.");
+#if !defined(OPENSSL_NO_ENGINE)
         ENGINE_load_builtin_engines();
         ENGINE *e;
         if (!(e = ENGINE_by_id(::Config.SSL.ssl_engine)))
             fatalf("Unable to find SSL engine '%s'\n", ::Config.SSL.ssl_engine);
 
         if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
-            const int ssl_error = ERR_get_error();
+            const auto ssl_error = ERR_get_error();
             fatalf("Failed to initialise SSL engine: %s\n", Security::ErrorString(ssl_error));
         }
-    }
-#else
-    if (::Config.SSL.ssl_engine)
-        fatalf("Your OpenSSL has no SSL engine support\n");
+#else /* OPENSSL_NO_ENGINE */
+        throw TextException("Cannot use ssl_engine in Squid built with OpenSSL configured to disable SSL engine support", Here());
 #endif
 
+#else /* OPENSSL_VERSION_MAJOR */
+        throw TextException("Cannot use ssl_engine in Squid built with OpenSSL 3.0 or newer", Here());
+#endif
+    }
+
     const char *defName = ::Config.SSL.certSignHash ? ::Config.SSL.certSignHash : SQUID_SSL_SIGN_HASH_IF_NONE;
     Ssl::DefaultSignHash = EVP_get_digestbyname(defName);
     if (!Ssl::DefaultSignHash)
