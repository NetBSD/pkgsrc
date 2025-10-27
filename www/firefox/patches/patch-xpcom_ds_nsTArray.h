$NetBSD: patch-xpcom_ds_nsTArray.h,v 1.1 2025/10/27 14:24:33 ryoon Exp $

* Fix segfault of about:newtab with web search form.
  Fix compililation by GCC (including 14 or earlier).
  From upstream: 449aa2cf94274a1ffbf006027ee686990b813219

--- xpcom/ds/nsTArray.h.orig	2025-10-24 00:10:00.574322510 +0000
+++ xpcom/ds/nsTArray.h
@@ -2972,7 +2972,7 @@ class MOZ_NON_MEMMOVABLE MOZ_GSL_OWNER A
       char mStorage[sizeof(value_type) * N];
     };
     AutoBuffer() : mHdr{.mLength = 0, .mCapacity = N, .mIsAutoArray = true} {}
-    ~AutoBuffer() {}
+    ~AutoBuffer() = default;
   } mAutoBuf;
   static_assert(offsetof(AutoBuffer, mStorage) == sizeof(nsTArrayHeader),
                 "Shouldn't have padding");
