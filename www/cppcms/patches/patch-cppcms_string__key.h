$NetBSD: patch-cppcms_string__key.h,v 1.1 2013/09/16 15:46:07 joerg Exp $

--- cppcms/string_key.h.orig	2013-09-16 15:24:39.524666221 +0000
+++ cppcms/string_key.h
@@ -248,7 +248,7 @@ namespace cppcms {
 		///
 		bool operator!=(string_key const &other) const
 		{
-			return !(*this!=other);
+			return !(*this==other);
 		}
 
 		///
