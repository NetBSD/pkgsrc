$NetBSD: patch-html_CharsetConverter.cc,v 1.1 2014/02/16 22:58:51 wiz Exp $

Fix build on NetBSD.

--- html/CharsetConverter.cc.orig	2011-05-15 17:32:10.000000000 +0000
+++ html/CharsetConverter.cc
@@ -37,7 +37,7 @@ string CharsetConverter::convert(const s
 
 	size_t ret;
 	while (1) {
-		ret = iconv(mIconvDescriptor, const_cast<char**>(&inbuf), &inbytesleft, &outbuf, &outbytesleft);
+		ret = iconv(mIconvDescriptor, (const char**)(&inbuf), &inbytesleft, &outbuf, &outbytesleft);
 		if (ret == 0) break;
 		if (ret == (size_t)-1 && errno == E2BIG) return string();
 
