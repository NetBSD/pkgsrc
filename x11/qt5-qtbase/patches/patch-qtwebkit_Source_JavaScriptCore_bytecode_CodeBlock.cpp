$NetBSD: patch-qtwebkit_Source_JavaScriptCore_bytecode_CodeBlock.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* From http://pkgs.fedoraproject.org/cgit/qt5-qtwebkit.git/tree/qtwebkit-opensource-src-5.2.0-beta1-nojit.patch
  Disable JIT support conditionally

--- qtwebkit/Source/JavaScriptCore/bytecode/CodeBlock.cpp.orig	2013-11-27 01:01:49.000000000 +0000
+++ qtwebkit/Source/JavaScriptCore/bytecode/CodeBlock.cpp
@@ -2947,8 +2947,12 @@ void CodeBlock::countReoptimization()
 
 unsigned CodeBlock::numberOfDFGCompiles()
 {
+#if ENABLE(JIT)
     ASSERT(JITCode::isBaselineCode(getJITType()));
     return (JITCode::isOptimizingJIT(replacement()->getJITType()) ? 1 : 0) + m_reoptimizationRetryCounter;
+#else
+    return 0;
+#endif
 }
 
 int32_t CodeBlock::codeTypeThresholdMultiplier() const
