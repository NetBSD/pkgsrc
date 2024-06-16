$NetBSD: patch-html_CharsetConverter.h,v 1.1 2024/06/16 18:55:44 wiz Exp $

Fix build with c++11 using
https://sourceforge.net/p/htmlcxx/patches/8/

--- html/CharsetConverter.h.orig	2011-02-13 22:24:53.000000000 +0000
+++ html/CharsetConverter.h
@@ -17,7 +17,7 @@ namespace htmlcxx
 						: std::runtime_error(arg) {}
 			};
 			
-			CharsetConverter(const std::string &from, const std::string &to) throw (Exception);
+			CharsetConverter(const std::string &from, const std::string &to);
 			~CharsetConverter();
 			
 			std::string convert(const std::string &input);
