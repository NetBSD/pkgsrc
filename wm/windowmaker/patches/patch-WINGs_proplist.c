$NetBSD: patch-WINGs_proplist.c,v 1.1 2013/05/23 15:08:50 joerg Exp $

--- WINGs/proplist.c.orig	2013-05-23 12:40:45.000000000 +0000
+++ WINGs/proplist.c
@@ -1162,7 +1162,7 @@ WMPropList *WMMergePLDictionaries(WMProp
 	WMPropList *key, *value, *dvalue;
 	WMHashEnumerator e;
 
-	wassertr(source->type == WPLDictionary && dest->type == WPLDictionary);
+	wassertrv(source->type == WPLDictionary && dest->type == WPLDictionary, NULL);
 
 	if (source == dest)
 		return dest;
@@ -1189,7 +1189,7 @@ WMPropList *WMSubtractPLDictionaries(WMP
 	WMPropList *key, *value, *dvalue;
 	WMHashEnumerator e;
 
-	wassertr(source->type == WPLDictionary && dest->type == WPLDictionary);
+	wassertrv(source->type == WPLDictionary && dest->type == WPLDictionary, NULL);
 
 	if (source == dest) {
 		WMPropList *keys = WMGetPLDictionaryKeys(dest);
