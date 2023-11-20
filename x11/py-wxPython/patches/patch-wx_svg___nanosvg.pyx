$NetBSD: patch-wx_svg___nanosvg.pyx,v 1.1 2023/11/20 12:24:39 gdt Exp $

Fix build with cython 3.
Taken from https://github.com/wxWidgets/Phoenix/pull/2441

--- wx/svg/_nanosvg.pyx.orig	2023-11-19 23:51:44.405729624 +0000
+++ wx/svg/_nanosvg.pyx
@@ -42,7 +42,6 @@ for manipulating the SVG shape info in m
 
 import sys
 
-cimport cython.object
 from cpython.buffer cimport (
     Py_buffer, PyObject_CheckBuffer, PyObject_GetBuffer, PyBUF_SIMPLE,
     PyBuffer_Release)
