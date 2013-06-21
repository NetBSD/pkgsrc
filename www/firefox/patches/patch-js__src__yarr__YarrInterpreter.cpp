$NetBSD: patch-js__src__yarr__YarrInterpreter.cpp,v 1.1 2013/06/21 23:11:42 ryoon Exp $

Bugzilla ticket #871444

diff -r 581ea0e6531e js/src/yarr/YarrInterpreter.cpp
--- js/src/yarr/YarrInterpreter.cpp	Tue May 07 09:47:43 2013 -0400
+++ js/src/yarr/YarrInterpreter.cpp	Sun May 12 17:41:08 2013 +0200
@@ -156,6 +156,7 @@
     ParenthesesDisjunctionContext* allocParenthesesDisjunctionContext(ByteDisjunction* disjunction, unsigned* output, ByteTerm& term)
     {
         size_t size = sizeof(ParenthesesDisjunctionContext) - sizeof(unsigned) + (term.atom.parenthesesDisjunction->m_numSubpatterns << 1) * sizeof(unsigned) + sizeof(DisjunctionContext) - sizeof(uintptr_t) + disjunction->m_frameSize * sizeof(uintptr_t);
+	size = JS_ROUNDUP(size, JS_ALIGNMENT_OF(ParenthesesDisjunctionContext));
         allocatorPool = allocatorPool->ensureCapacity(size);
         if (!allocatorPool)
             CRASH();
