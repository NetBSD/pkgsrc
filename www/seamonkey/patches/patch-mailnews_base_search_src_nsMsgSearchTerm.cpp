$NetBSD: patch-mailnews_base_search_src_nsMsgSearchTerm.cpp,v 1.4 2021/02/08 12:26:20 ryoon Exp $

--- comm/mailnews/base/search/src/nsMsgSearchTerm.cpp.orig	2020-02-17 23:36:19.000000000 +0000
+++ comm/mailnews/base/search/src/nsMsgSearchTerm.cpp
@@ -207,7 +207,7 @@ nsresult NS_MsgGetStringForAttribute(int
     }
   }
   if (!found)
-    *string = ""; // don't leave the string uninitialized
+    *string = NULL; // don't leave the string uninitialized
 
   // we no longer return invalid attribute. If we cannot find the string in the table,
   // then it is an arbitrary header. Return success regardless if found or not
