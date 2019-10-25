$NetBSD: patch-html_CharsetConverter.cc,v 1.2 2019/10/25 10:29:04 kamil Exp $

Fix build on NetBSD.

--- html/CharsetConverter.cc.orig	2011-05-15 17:32:10.000000000 +0000
+++ html/CharsetConverter.cc
@@ -4,6 +4,15 @@
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
 
