$NetBSD: patch-image_Downscaler.h,v 1.1 2017/04/27 01:55:57 ryoon Exp $

--- image/Downscaler.h.orig	2016-10-31 20:15:32.000000000 +0000
+++ image/Downscaler.h
@@ -154,14 +154,14 @@ private:
 class Downscaler
 {
 public:
-  explicit Downscaler(const nsIntSize&)
+  explicit Downscaler(const nsIntSize&) : mScale(1.0, 1.0)
   {
     MOZ_RELEASE_ASSERT(false, "Skia is not enabled");
   }
 
-  const nsIntSize& OriginalSize() const { return nsIntSize(); }
-  const nsIntSize& TargetSize() const { return nsIntSize(); }
-  const gfxSize& Scale() const { return gfxSize(1.0, 1.0); }
+  const nsIntSize& OriginalSize() const { return mSize; }
+  const nsIntSize& TargetSize() const { return mSize; }
+  const gfxSize& Scale() const { return mScale; }
 
   nsresult BeginFrame(const nsIntSize&, const Maybe<nsIntRect>&, uint8_t*, bool, bool = false)
   {
@@ -177,6 +177,9 @@ public:
   DownscalerInvalidRect TakeInvalidRect() { return DownscalerInvalidRect(); }
   void ResetForNextProgressivePass() { }
   const nsIntSize FrameSize() const { return nsIntSize(0, 0); }
+private:
+  nsIntSize mSize;
+  gfxSize mScale;
 };
 
 #endif // MOZ_ENABLE_SKIA
