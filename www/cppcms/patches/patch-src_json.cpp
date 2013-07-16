$NetBSD: patch-src_json.cpp,v 1.1 2013/07/16 10:12:48 joerg Exp $

--- src/json.cpp.orig	2013-01-02 22:26:03.000000000 +0000
+++ src/json.cpp
@@ -785,7 +785,7 @@ namespace json {
 			bool parse_number()
 			{
 				is_ >> real;
-				return is_;
+				return is_.good() || is_.eof();
 			}
 			
 		};
