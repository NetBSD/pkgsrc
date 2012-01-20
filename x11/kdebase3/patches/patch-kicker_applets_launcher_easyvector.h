$NetBSD: patch-kicker_applets_launcher_easyvector.h,v 1.1 2012/01/20 16:59:20 joerg Exp $

--- kicker/applets/launcher/easyvector.h.orig	2012-01-18 21:40:53.000000000 +0000
+++ kicker/applets/launcher/easyvector.h
@@ -87,7 +87,7 @@ typename EasyVector< VALUE, CHECKINDEX >
 template < class VALUE, bool CHECKINDEX >
 void EasyVector< VALUE, CHECKINDEX >::eraseAt(Index index)
 {   _checkIndex(index);
-    erase(this->begin()+index);
+    this->erase(this->begin()+index);
 }
 
 
@@ -108,7 +108,7 @@ void EasyVector< VALUE, CHECKINDEX >::in
         this->push_back(value);
         return;
     }
-    insert(this->begin()+index,value);
+    this->insert(this->begin()+index,value);
 }
 
 
@@ -116,7 +116,7 @@ template < class VALUE, bool CHECKINDEX 
 void EasyVector< VALUE, CHECKINDEX >::insertAt(EasyVector< VALUE, CHECKINDEX >::Index index,const EasyVector< VALUE, CHECKINDEX > &v)
 {   index=_convertInsertIndex(index);
     _checkInsertIndex(index);
-    insert(this->begin()+index,v.begin(),v.end());
+    this->insert(this->begin()+index,v.begin(),v.end());
 }
 
 
