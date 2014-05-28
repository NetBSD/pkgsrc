$NetBSD: patch-gfx_src_nsDeviceContext.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

* gfxPDFSurface.h must be included whenever MOZ_PDF_PRINTING is
  defined. In fact !defined(MOZ_WIDGET_COCOA) nearly equals to
  defined(MOZ_PDF_PRINTING) but it isn't the same as
  !defined(XP_MACOSX). In short cocoa toolkit is wrongly assumed here
  too.

* Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/src/nsDeviceContext.cpp.orig	2014-05-06 22:55:35.000000000 +0000
+++ gfx/src/nsDeviceContext.cpp
@@ -35,7 +35,7 @@
 #include "nsThreadUtils.h"              // for NS_IsMainThread
 #include "nsTraceRefcnt.h"              // for MOZ_COUNT_CTOR, etc
 
-#if !XP_MACOSX
+#if defined(MOZ_PDF_PRINTING)
 #include "gfxPDFSurface.h"
 #endif
 
@@ -45,7 +45,7 @@
 #include "gfxWindowsSurface.h"
 #elif defined(XP_OS2)
 #include "gfxOS2Surface.h"
-#elif XP_MACOSX
+#elif defined(MOZ_WIDGET_COCOA)
 #include "gfxQuartzSurface.h"
 #endif
 
@@ -392,7 +392,7 @@ nsresult
 nsDeviceContext::CreateRenderingContext(nsRenderingContext *&aContext)
 {
     nsRefPtr<gfxASurface> printingSurface = mPrintingSurface;
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // CreateRenderingContext() can be called (on reflow) after EndPage()
     // but before BeginPage().  On OS X (and only there) mPrintingSurface
     // will in this case be null, because OS X printing surfaces are
@@ -551,7 +551,7 @@ nsDeviceContext::BeginPage(void)
 
     if (NS_FAILED(rv)) return rv;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // We need to get a new surface for each page on the Mac, as the
     // CGContextRefs are only good for one page.
     mDeviceContextSpec->GetSurfaceForPrinter(getter_AddRefs(mPrintingSurface));
@@ -567,7 +567,7 @@ nsDeviceContext::EndPage(void)
 {
     nsresult rv = mPrintingSurface->EndPage();
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // We need to release the CGContextRef in the surface here, plus it's
     // not something you would want anyway, as these CGContextRefs are only
     // good for one page.  But we need to keep a cached reference to it, since
@@ -674,7 +674,7 @@ nsDeviceContext::CalcPrintingSize()
         break;
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     case gfxSurfaceType::Quartz:
         inPoints = true; // this is really only true when we're printing
         size = reinterpret_cast<gfxQuartzSurface*>(mPrintingSurface.get())->GetSize();
