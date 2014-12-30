$NetBSD: patch-config.tests_unix_iconv_iconv.cpp,v 1.1 2014/12/30 17:23:46 adam Exp $

* Fix for NetBSD iconv(3)

--- config.tests/unix/iconv/iconv.cpp.orig	2013-11-27 01:01:17.000000000 +0000
+++ config.tests/unix/iconv/iconv.cpp
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
