$NetBSD: patch-Source_JavaScriptCore_runtime_IntlSegments.cpp,v 1.1 2021/04/25 12:00:24 leot Exp $

Fix build for ICU >= 69.

From:

 https://trac.webkit.org/changeset/275920/webkit?format=diff&new=275920

--- Source/JavaScriptCore/runtime/IntlSegments.cpp.orig	2021-02-26 09:57:05.000000000 +0000
+++ Source/JavaScriptCore/runtime/IntlSegments.cpp
@@ -100,7 +100,7 @@ JSObject* IntlSegments::createSegmentIte
     auto scope = DECLARE_THROW_SCOPE(vm);
 
     UErrorCode status = U_ZERO_ERROR;
-    auto segmenter = std::unique_ptr<UBreakIterator, UBreakIteratorDeleter>(ubrk_safeClone(m_segmenter.get(), nullptr, nullptr, &status));
+    auto segmenter = std::unique_ptr<UBreakIterator, UBreakIteratorDeleter>(cloneUBreakIterator(m_segmenter.get(), &status));
     if (U_FAILURE(status)) {
         throwTypeError(globalObject, scope, "failed to initialize SegmentIterator"_s);
         return nullptr;
