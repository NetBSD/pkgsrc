$NetBSD: patch-XS_Colour.xs,v 1.1 2018/09/27 22:32:28 tnn Exp $

GetPixel() not supported with GTK3

--- XS/Colour.xs.orig	2014-03-08 13:01:15.000000000 +0000
+++ XS/Colour.xs
@@ -114,7 +114,7 @@ wxColour::GetAsString( long flags )
 
 #endif
 
-#if !defined(__WXMAC__)
+#if 0
 
 long
 wxColour::GetPixel()
