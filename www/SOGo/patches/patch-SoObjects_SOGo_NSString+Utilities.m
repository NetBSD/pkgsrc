$NetBSD: patch-SoObjects_SOGo_NSString+Utilities.m,v 1.3 2023/01/17 14:26:54 manu Exp $

Works around the CalDAV client breaking Byte-Order Mark that 
gnustep-base adds starting with version 1.28 

From upstream
https://github.com/Alinto/sogo/pull/324

--- SoObjects/SOGo/NSString+Utilities.m.orig	2023-01-17 08:41:21.165930102 +0100
+++ SoObjects/SOGo/NSString+Utilities.m	2023-01-17 08:42:08.993684418 +0100
@@ -346,9 +346,9 @@
   unsigned escapeCount;
 
   if ([self length] == 0) return @"";
 
-  NSData *data = [self dataUsingEncoding:NSUTF32StringEncoding];
+  NSData *data = [self dataUsingEncoding:NSUTF32LittleEndianStringEncoding];
   chars = [data bytes];
   len = [data length]/4;
 
   /* check for characters to escape ... */
@@ -417,9 +417,9 @@
   }
 
   self = [[NSString alloc] initWithBytesNoCopy: buf
                                         length: (j*sizeof(wchar_t))
-                                      encoding: NSUTF32StringEncoding
+                                      encoding: NSUTF32LittleEndianStringEncoding
                                   freeWhenDone: YES];
 
   return [self autorelease];
 }
