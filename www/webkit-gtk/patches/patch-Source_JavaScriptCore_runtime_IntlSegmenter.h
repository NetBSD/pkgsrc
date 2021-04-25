$NetBSD: patch-Source_JavaScriptCore_runtime_IntlSegmenter.h,v 1.1 2021/04/25 12:00:24 leot Exp $

Fix build for ICU >= 69.

From:

 https://trac.webkit.org/changeset/275920/webkit?format=diff&new=275920

--- Source/JavaScriptCore/runtime/IntlSegmenter.h.orig	2021-02-26 09:57:05.000000000 +0000
+++ Source/JavaScriptCore/runtime/IntlSegmenter.h
@@ -75,4 +75,8 @@ private:
     Granularity m_granularity { Granularity::Grapheme };
 };
 
+// Abstraction to call ubrk_safeClone or ubrk_clone depending on ICU version.
+// This is implemented in IntlWorkaround.cpp in order to confine draft API visibility.
+UBreakIterator* cloneUBreakIterator(const UBreakIterator*, UErrorCode*);
+
 } // namespace JSC
