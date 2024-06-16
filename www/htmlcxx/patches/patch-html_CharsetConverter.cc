$NetBSD: patch-html_CharsetConverter.cc,v 1.3 2024/06/16 18:55:44 wiz Exp $

Fix build on NetBSD.

Fix build with c++11, from
https://sourceforge.net/p/htmlcxx/patches/8/

--- html/CharsetConverter.cc.orig	2011-05-15 17:32:10.000000000 +0000
+++ html/CharsetConverter.cc
@@ -4,10 +4,19 @@
 #include <cerrno>
 #include "CharsetConverter.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 using namespace std;
 using namespace htmlcxx;
 
-CharsetConverter::CharsetConverter(const string &from, const string &to) throw (Exception)
+CharsetConverter::CharsetConverter(const string &from, const string &to)
 {
 	mIconvDescriptor = iconv_open(to.c_str(), from.c_str());
 	if (mIconvDescriptor == (iconv_t)(-1))
@@ -37,7 +46,11 @@ string CharsetConverter::convert(const s
 
 	size_t ret;
 	while (1) {
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV)
+		ret = iconv(mIconvDescriptor, (const char**)(&inbuf), &inbytesleft, &outbuf, &outbytesleft);
+#else
 		ret = iconv(mIconvDescriptor, const_cast<char**>(&inbuf), &inbytesleft, &outbuf, &outbytesleft);
+#endif
 		if (ret == 0) break;
 		if (ret == (size_t)-1 && errno == E2BIG) return string();
 
