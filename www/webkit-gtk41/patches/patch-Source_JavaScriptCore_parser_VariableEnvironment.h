$NetBSD: patch-Source_JavaScriptCore_parser_VariableEnvironment.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

Undefine X11 macro that conflicts with enum value.
X11/X.h defines Success=0, which breaks PrivateDeclarationResult enum.
https://github.com/WebKit/WebKit/pull/64743

--- Source/JavaScriptCore/parser/VariableEnvironment.h.orig	2026-04-19 05:55:05.008914400 +0000
+++ Source/JavaScriptCore/parser/VariableEnvironment.h
@@ -32,6 +32,11 @@
 #include <wtf/PackedRefPtr.h>
 #include <wtf/TZoneMalloc.h>
 
+// X11/X.h defines Success as 0, conflicting with our enum value
+#ifdef Success
+#undef Success
+#endif
+
 namespace JSC {
 
 struct VariableEnvironmentEntry {
