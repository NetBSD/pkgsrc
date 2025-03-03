$NetBSD: patch-Source_GSCharacterPanel.m,v 1.2 2025/03/03 01:26:21 manu Exp $

Adhoc patch to adapt icu-68 Fallout

--- ./Source/GSCharacterPanel.m.orig	2025-02-11 19:44:11.000000000 +0100
+++ ./Source/GSCharacterPanel.m	2025-03-03 01:45:00.162397109 +0100
@@ -89,9 +89,9 @@
 
 static UBool enumCharNamesFn(void *context, UChar32 code, UCharNameChoice nameChoice, const char *name, int32_t length)
 {
   [(NSMutableIndexSet*)context addIndex: (NSUInteger)code];
-  return TRUE;
+  return true;
 }
 
 static NSIndexSet *AssignedCodepoints()
 {
@@ -114,9 +114,9 @@
   if (strstr(name, ctx->searchString) != NULL)
     {
       [ctx->set addIndex: (NSUInteger)code];
     }
-  return TRUE;
+  return true;
 }
 
 static NSIndexSet *CodepointsWithNameContainingSubstring(NSString *str)
 {
