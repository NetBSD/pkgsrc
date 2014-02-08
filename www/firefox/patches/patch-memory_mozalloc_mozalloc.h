$NetBSD: patch-memory_mozalloc_mozalloc.h,v 1.2 2014/02/08 09:36:00 ryoon Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=928808

--- memory/mozalloc/mozalloc.h.orig	2014-01-28 04:03:59.000000000 +0000
+++ memory/mozalloc/mozalloc.h
@@ -39,15 +39,6 @@
 #  define MOZALLOC_EXPORT
 #endif
 
-
-#if defined(MOZ_ALWAYS_INLINE_EVEN_DEBUG)
-#  define MOZALLOC_INLINE MOZ_ALWAYS_INLINE_EVEN_DEBUG
-#elif defined(HAVE_FORCEINLINE)
-#  define MOZALLOC_INLINE __forceinline
-#else
-#  define MOZALLOC_INLINE inline
-#endif
-
 /* Workaround build problem with Sun Studio 12 */
 #if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
 #  undef NS_WARN_UNUSED_RESULT
@@ -171,15 +162,6 @@ MOZALLOC_EXPORT void* moz_valloc(size_t 
  * that |::operator new() throw(std::bad_alloc)| will never return NULL.
  */
 
-/* NB: This is defined just to silence vacuous warnings about symbol
- * visibility on OS X/gcc. These symbols are force-inline and not
- * exported. */
-#if defined(XP_MACOSX)
-#  define MOZALLOC_EXPORT_NEW MOZALLOC_EXPORT
-#else
-#  define MOZALLOC_EXPORT_NEW
-#endif
-
 #if defined(ANDROID) || defined(_MSC_VER)
 /*
  * Android doesn't fully support exceptions, so its <new> header
@@ -195,53 +177,29 @@ MOZALLOC_EXPORT void* moz_valloc(size_t 
 
 #define MOZALLOC_THROW_BAD_ALLOC MOZALLOC_THROW_BAD_ALLOC_IF_HAS_EXCEPTIONS
 
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void* operator new(size_t size) MOZALLOC_THROW_BAD_ALLOC
-{
-    return moz_xmalloc(size);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void* operator new(size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_malloc(size);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void* operator new[](size_t size) MOZALLOC_THROW_BAD_ALLOC
-{
-    return moz_xmalloc(size);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void* operator new[](size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_malloc(size);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void operator delete(void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_free(ptr);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void operator delete(void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_free(ptr);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void operator delete[](void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_free(ptr);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void operator delete[](void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_free(ptr);
-}
+MOZALLOC_EXPORT
+void* operator new(size_t size) MOZALLOC_THROW_BAD_ALLOC;
+
+MOZALLOC_EXPORT
+void* operator new(size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size) MOZALLOC_THROW_BAD_ALLOC;
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
 
 
 /*
@@ -263,29 +221,17 @@ void operator delete[](void* ptr, const 
  *   (4) the matching system |operator delete(void*) throw(std::bad_alloc)|
  */
 
-MOZALLOC_INLINE
-void* operator new(size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_malloc(size);
-}
-
-MOZALLOC_INLINE
-void* operator new[](size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_malloc(size);
-}
-
-MOZALLOC_INLINE
-void operator delete(void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    moz_free(ptr);
-}
-
-MOZALLOC_INLINE
-void operator delete[](void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    moz_free(ptr);
-}
+MOZALLOC_EXPORT
+void* operator new(size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
 
 #endif  /* ifdef __cplusplus */
 
