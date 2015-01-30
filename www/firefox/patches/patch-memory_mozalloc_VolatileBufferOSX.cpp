$NetBSD: patch-memory_mozalloc_VolatileBufferOSX.cpp,v 1.1 2015/01/30 07:32:24 pho Exp $

Try to fallback to valloc(3) if posix_memalign(3) is not avialble. It
has been added since MacOS 10.6.

--- memory/mozalloc/VolatileBufferOSX.cpp.orig	2015-01-28 23:40:15.000000000 +0000
+++ memory/mozalloc/VolatileBufferOSX.cpp
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
