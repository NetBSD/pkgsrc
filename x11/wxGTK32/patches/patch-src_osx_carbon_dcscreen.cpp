$NetBSD: patch-src_osx_carbon_dcscreen.cpp,v 1.1 2024/12/26 18:10:23 adam Exp $

Fix wxOSX wxScreenDC compilation against SDK 15.0
https://github.com/vadz/wxWidgets/commit/87617efbe1e840590db6040f0866d0ac9fdc6bcf

--- src/osx/carbon/dcscreen.cpp.orig	2024-12-26 18:03:39.853800381 +0000
+++ src/osx/carbon/dcscreen.cpp
@@ -14,6 +14,7 @@
 #include "wx/osx/dcscreen.h"
 
 #include "wx/osx/private.h"
+#include "wx/osx/private/available.h"
 #include "wx/graphics.h"
 
 wxIMPLEMENT_ABSTRACT_CLASS(wxScreenDCImpl, wxWindowDCImpl);
@@ -69,14 +70,25 @@ wxBitmap wxScreenDCImpl::DoGetAsBitmap(c
         srcRect = CGRectOffset( srcRect, -subrect->x, -subrect->y ) ;
 
     CGImageRef image = NULL;
-    
-    image = CGDisplayCreateImage(kCGDirectMainDisplay);
 
-    wxASSERT_MSG(image, wxT("wxScreenDC::GetAsBitmap - unable to get screenshot."));
-
-    CGContextDrawImage(context, srcRect, image);
+#if __MAC_OS_X_VERSION_MAX_ALLOWED >= 140000
+    if ( WX_IS_MACOS_AVAILABLE(14, 4) ) // errors on lower versions of macOS 14
+    {
+        // TODO add ScreenKit implementation
+    }
+    else
+#endif // macOS 10.14+
+    {
+#if __MAC_OS_X_VERSION_MAX_ALLOWED < 150000
+        image = CGDisplayCreateImage(kCGDirectMainDisplay);
+#endif
+    }
 
-    CGImageRelease(image);
+    if ( image != NULL )
+    {
+        CGContextDrawImage(context, srcRect, image);
+        CGImageRelease(image);
+    }
 
     CGContextRestoreGState(context);
 #else
