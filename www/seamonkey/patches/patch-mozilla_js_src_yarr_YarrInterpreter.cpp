$NetBSD: patch-mozilla_js_src_yarr_YarrInterpreter.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/yarr/YarrInterpreter.cpp.orig	2013-06-20 04:35:09.000000000 +0000
+++ mozilla/js/src/yarr/YarrInterpreter.cpp
@@ -156,6 +156,7 @@ public:
     ParenthesesDisjunctionContext* allocParenthesesDisjunctionContext(ByteDisjunction* disjunction, unsigned* output, ByteTerm& term)
     {
         size_t size = sizeof(ParenthesesDisjunctionContext) - sizeof(unsigned) + (term.atom.parenthesesDisjunction->m_numSubpatterns << 1) * sizeof(unsigned) + sizeof(DisjunctionContext) - sizeof(uintptr_t) + disjunction->m_frameSize * sizeof(uintptr_t);
+	size = JS_ROUNDUP(size, JS_ALIGNMENT_OF(ParenthesesDisjunctionContext));
         allocatorPool = allocatorPool->ensureCapacity(size);
         if (!allocatorPool)
             CRASH();
