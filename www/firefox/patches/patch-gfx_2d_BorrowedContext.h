$NetBSD: patch-gfx_2d_BorrowedContext.h,v 1.1 2017/02/05 15:41:58 martin Exp $

Backport of upstream commit 
	https://hg.mozilla.org/mozilla-central/rev/c1e18cb7926e

diff gfx/2d/BorrowedContext.h.orig gfx/2d/BorrowedContext.h
--- gfx/2d/BorrowedContext.h.orig
+++ gfx/2d/BorrowedContext.h
@@ -190,18 +190,28 @@ public:
   }
 
   ~BorrowedCGContext() {
     MOZ_ASSERT(!cg);
   }
 
   CGContextRef cg;
 private:
+#ifdef USE_SKIA
   static CGContextRef BorrowCGContextFromDrawTarget(DrawTarget *aDT);
   static void ReturnCGContextToDrawTarget(DrawTarget *aDT, CGContextRef cg);
+#else
+  static CGContextRef BorrowCGContextFromDrawTarget(DrawTarget *aDT) {
+    MOZ_CRASH("Not supported without Skia");
+  }
+
+  static void ReturnCGContextToDrawTarget(DrawTarget *aDT, CGContextRef cg) {
+    MOZ_CRASH("not supported without Skia");
+  }
+#endif
   DrawTarget *mDT;
 };
 #endif
 
 } // namespace gfx
 } // namespace mozilla
 
 #endif // _MOZILLA_GFX_BORROWED_CONTEXT_H




