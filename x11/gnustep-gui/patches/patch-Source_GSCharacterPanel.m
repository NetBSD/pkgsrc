$NetBSD: patch-Source_GSCharacterPanel.m,v 1.1 2020/11/13 02:47:45 mef Exp $

Adhoc patch to adapt icu-68 Fallout

--- Source/GSCharacterPanel.m.orig	2020-04-05 20:04:40.000000000 +0000
+++ Source/GSCharacterPanel.m
@@ -78,7 +78,7 @@
 static UBool enumCharNamesFn(void *context, UChar32 code, UCharNameChoice nameChoice, const char *name, int32_t length)
 {
   [(NSMutableIndexSet*)context addIndex: (NSUInteger)code];
-  return TRUE;
+  return true;
 }
 
 static NSIndexSet *AssignedCodepoints()
@@ -103,7 +103,7 @@ static UBool searchCharNamesFn(void *con
     {
       [ctx->set addIndex: (NSUInteger)code];
     }
-  return TRUE;
+  return true;
 }
 
 static NSIndexSet *CodepointsWithNameContainingSubstring(NSString *str)
