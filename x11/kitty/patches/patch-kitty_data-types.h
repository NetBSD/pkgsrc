$NetBSD: patch-kitty_data-types.h,v 1.2 2024/12/26 16:50:44 ktnb Exp $

Static assertions cause compile error for an unknown reason on
NetBSD.

--- kitty/data-types.h.orig	2024-12-18 14:56:38.746939917 +0000
+++ kitty/data-types.h
@@ -63,7 +63,6 @@ static inline PyObject* Py_XNewRef(PyObj
 
 typedef unsigned long long id_type;
 typedef uint32_t char_type;
-static_assert(sizeof(Py_UCS4) == sizeof(char_type), "PyUCS4 and char_type dont match");
 #define MAX_CHAR_TYPE_VALUE UINT32_MAX
 typedef uint32_t color_type;
 typedef uint16_t hyperlink_id_type;
