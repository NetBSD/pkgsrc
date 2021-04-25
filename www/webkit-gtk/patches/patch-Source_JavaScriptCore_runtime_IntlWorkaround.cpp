$NetBSD: patch-Source_JavaScriptCore_runtime_IntlWorkaround.cpp,v 1.1 2021/04/25 12:00:24 leot Exp $

Fix build for ICU >= 69.

From:

 https://trac.webkit.org/changeset/275920/webkit?format=diff&new=275920

--- Source/JavaScriptCore/runtime/IntlWorkaround.cpp.orig	2021-04-25 09:57:43.581734903 +0000
+++ Source/JavaScriptCore/runtime/IntlWorkaround.cpp
@@ -0,0 +1,53 @@
+/*
+ * Copyright (C) 2021 Sony Interactive Entertainment Inc.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ *
+ * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
+ * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
+ * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
+ * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
+ * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
+ * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
+ * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
+ * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
+ * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
+ * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
+ * THE POSSIBILITY OF SUCH DAMAGE.
+ */
+
+#include "config.h"
+
+#include <unicode/uvernum.h>
+
+// ICU 69 introduces draft API ubrk_clone and deprecates ubrk_safeClone.
+#if U_ICU_VERSION_MAJOR_NUM >= 69
+#define HAVE_ICU_UBRK_CLONE 1
+#endif
+
+#if defined(U_HIDE_DRAFT_API)
+#undef U_HIDE_DRAFT_API
+#endif
+#include <unicode/ubrk.h>
+
+namespace JSC {
+
+UBreakIterator* cloneUBreakIterator(const UBreakIterator*, UErrorCode*);
+
+UBreakIterator* cloneUBreakIterator(const UBreakIterator* iterator, UErrorCode* status)
+{
+#if HAVE(ICU_UBRK_CLONE)
+    return ubrk_clone(iterator, status);
+#else
+    return ubrk_safeClone(iterator, nullptr, nullptr, status);
+#endif
+}
+
+} // namespace JSC
