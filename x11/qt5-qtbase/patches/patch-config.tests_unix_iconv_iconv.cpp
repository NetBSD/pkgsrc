$NetBSD: patch-config.tests_unix_iconv_iconv.cpp,v 1.2 2018/01/17 19:30:47 markd Exp $

Fix for NetBSD iconv(3)

--- config.tests/iconv/iconv.cpp.orig	2017-10-02 08:43:38.000000000 +0000
+++ config.tests/iconv/iconv.cpp
@@ -43,7 +43,11 @@ int main(int, char **)
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
