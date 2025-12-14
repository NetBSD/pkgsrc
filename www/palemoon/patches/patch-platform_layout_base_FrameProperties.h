$NetBSD: patch-platform_layout_base_FrameProperties.h,v 1.1 2025/12/14 18:05:18 martin Exp $

Fix crash on big endian 32bit platforms.
Just start the browser and press F12 for dev tools.

--- platform/layout/base/FrameProperties.h.orig	2025-10-15 19:46:52.000000000 +0200
+++ platform/layout/base/FrameProperties.h	2025-12-14 09:14:24.451706944 +0100
@@ -310,15 +310,35 @@
 
     static uint64_t ToInternalValue(PropertyType<T> aValue)
     {
-      uint64_t v = 0;
-      memcpy(&v, &aValue, sizeof(aValue));
-      return v;
+#ifndef _LP64
+      if (sizeof(PropertyType<T>) <= sizeof(uint32_t)) {
+          // make sure to loose the unimportant half on 32bit architectures
+          uint32_t v = 0;
+	  memcpy(&v, &aValue, sizeof(aValue));
+	  return v;
+      } else {
+#endif
+          uint64_t v = 0;
+          memcpy(&v, &aValue, sizeof(aValue));
+          return v;
+#ifndef _LP64
+      }
+#endif
     }
 
     static PropertyType<T> FromInternalValue(uint64_t aInternalValue)
     {
       PropertyType<T> value;
-      memcpy(&value, &aInternalValue, sizeof(value));
+#ifndef _LP64
+      if (sizeof(value) <= sizeof(uint32_t)) {
+          uint32_t v32 = (uint32_t)aInternalValue;
+	  memcpy(&value, &v32, sizeof(value));
+      } else {
+#endif
+          memcpy(&value, &aInternalValue, sizeof(value));
+#ifndef _LP64
+      }
+#endif
       return value;
     }
   };
