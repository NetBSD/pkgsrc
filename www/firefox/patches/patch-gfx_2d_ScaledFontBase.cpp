$NetBSD: patch-gfx_2d_ScaledFontBase.cpp,v 1.1 2017/08/15 01:24:47 ryoon Exp $

* Support bigendian architectures

--- gfx/2d/ScaledFontBase.cpp.orig	2017-07-31 16:20:54.000000000 +0000
+++ gfx/2d/ScaledFontBase.cpp
@@ -212,14 +212,16 @@ ScaledFontBase::CopyGlyphsToBuilder(cons
     cairoPath->AppendPathToBuilder(builder);
     return;
   }
+#endif
+#ifdef USE_SKIA
   if (backendType == BackendType::RECORDING) {
     SkPath skPath = GetSkiaPathForGlyphs(aBuffer);
     RefPtr<Path> path = MakeAndAddRef<PathSkia>(skPath, FillRule::FILL_WINDING);
     path->StreamToSink(aBuilder);
     return;
   }
-  MOZ_ASSERT(false, "Path not being copied");
 #endif
+  MOZ_ASSERT(false, "Path not being copied");
 }
 
 void
