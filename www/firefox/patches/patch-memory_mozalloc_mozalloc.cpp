$NetBSD: patch-memory_mozalloc_mozalloc.cpp,v 1.1 2013/11/29 13:00:32 joerg Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=928808

--- memory/mozalloc/mozalloc.cpp.orig	2013-10-25 22:27:35.000000000 +0000
+++ memory/mozalloc/mozalloc.cpp
@@ -229,3 +229,76 @@ namespace mozilla {
 const fallible_t fallible = fallible_t();
 
 } // namespace mozilla
+
+
+MOZALLOC_EXPORT
+void* operator new(size_t size) MOZALLOC_THROW_BAD_ALLOC
+{
+    return moz_xmalloc(size);
+}
+
+MOZALLOC_EXPORT
+void* operator new(size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    return moz_malloc(size);
+}
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size) MOZALLOC_THROW_BAD_ALLOC
+{
+    return moz_xmalloc(size);
+}
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    return moz_malloc(size);
+}
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    return moz_free(ptr);
+}
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    return moz_free(ptr);
+}
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    return moz_free(ptr);
+}
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    return moz_free(ptr);
+}
+
+MOZALLOC_EXPORT
+void* operator new(size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    return moz_malloc(size);
+}
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    return moz_malloc(size);
+}
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    moz_free(ptr);
+}
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
+{
+    moz_free(ptr);
+}
