$NetBSD: patch-js_public_Utility.h,v 1.1 2024/08/01 15:41:09 ryoon Exp $

--- js/public/Utility.h.orig	2024-07-04 17:04:15.000000000 +0000
+++ js/public/Utility.h
@@ -482,9 +482,6 @@ static inline void js_free(void* p) {
 #define JS_DECLARE_NEW_METHODS(NEWNAME, ALLOCATOR, QUALIFIERS)              \
   template <class T, typename... Args>                                      \
   QUALIFIERS T* MOZ_HEAP_ALLOCATOR NEWNAME(Args&&... args) {                \
-    static_assert(                                                          \
-        alignof(T) <= alignof(max_align_t),                                 \
-        "over-aligned type is not supported by JS_DECLARE_NEW_METHODS");    \
     void* memory = ALLOCATOR(sizeof(T));                                    \
     return MOZ_LIKELY(memory) ? new (memory) T(std::forward<Args>(args)...) \
                               : nullptr;                                    \
@@ -501,9 +498,6 @@ static inline void js_free(void* p) {
 #define JS_DECLARE_NEW_ARENA_METHODS(NEWNAME, ALLOCATOR, QUALIFIERS)           \
   template <class T, typename... Args>                                         \
   QUALIFIERS T* MOZ_HEAP_ALLOCATOR NEWNAME(arena_id_t arena, Args&&... args) { \
-    static_assert(                                                             \
-        alignof(T) <= alignof(max_align_t),                                    \
-        "over-aligned type is not supported by JS_DECLARE_NEW_ARENA_METHODS"); \
     void* memory = ALLOCATOR(arena, sizeof(T));                                \
     return MOZ_LIKELY(memory) ? new (memory) T(std::forward<Args>(args)...)    \
                               : nullptr;                                       \
