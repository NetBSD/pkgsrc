$NetBSD: patch-qtbase_config.tests_unix_iconv_iconv.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Fix for NetBSD iconv(3)

--- qtbase/config.tests/unix/iconv/iconv.cpp.orig	2013-11-27 01:01:17.000000000 +0000
+++ qtbase/config.tests/unix/iconv/iconv.cpp
@@ -48,7 +48,11 @@ int main(int, char **)
 {
     iconv_t x = iconv_open("", "");
 
+#if defined(__NetBSD__)
+    const char *inp;
+#else
     char *inp;
+#endif
     char *outp;
     size_t inbytes, outbytes;
     iconv(x, &inp, &inbytes, &outp, &outbytes);
