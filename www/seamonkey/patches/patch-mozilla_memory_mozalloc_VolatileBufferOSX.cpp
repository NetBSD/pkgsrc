$NetBSD: patch-mozilla_memory_mozalloc_VolatileBufferOSX.cpp,v 1.1 2015/02/15 02:11:03 ryoon Exp $

--- mozilla/memory/mozalloc/VolatileBufferOSX.cpp.orig	2015-02-05 04:39:05.000000000 +0000
+++ mozilla/memory/mozalloc/VolatileBufferOSX.cpp
@@ -46,7 +46,14 @@ VolatileBuffer::Init(size_t aSize, size_
   }
 
 heap_alloc:
+#if defined(HAVE_POSIX_MEMALIGN)
   (void)moz_posix_memalign(&mBuf, aAlignment, aSize);
+#else
+  MOZ_RELEASE_ASSERT(
+      !(aAlignment > (size_t)getpagesize()),
+      "Cannot fallback to valloc(3): alignment is larger than the page size");
+  mBuf = valloc(aSize);
+#endif
   mHeap = true;
   return !!mBuf;
 }
