$NetBSD: patch-src_corelib_plugin_qelfparser__p.cpp,v 1.2 2023/03/25 07:29:32 nros Exp $

* Support older ELFOSABI_LINUX that has been replaced with ELFOSABI_GNU.
  Needed on NetBSD 9.

* Enable Alpha support
  From upstream:
  https://codereview.qt-project.org/c/qt/qtbase/+/437349

--- src/corelib/plugin/qelfparser_p.cpp.orig	2022-11-03 12:40:18.000000000 +0000
+++ src/corelib/plugin/qelfparser_p.cpp
@@ -20,6 +20,11 @@
 #  error "Need ELF header to parse plugins."
 #endif
 
+// support older ELFOSABI define for GNU/Linux
+#if !defined(ELFOSABI_GNU) && defined(ELFOSABI_LINUX)
+#define ELFOSABI_GNU ELFOSABI_LINUX
+#endif
+
 QT_BEGIN_NAMESPACE
 
 using namespace Qt::StringLiterals;
@@ -107,6 +112,8 @@ struct ElfMachineCheck
     static const Elf32_Half ExpectedMachine =
 #if 0
             // nothing
+#elif defined(Q_PROCESSOR_ALPHA)
+            EM_ALPHA
 #elif defined(Q_PROCESSOR_ARM_32)
             EM_ARM
 #elif defined(Q_PROCESSOR_ARM_64)
@@ -371,6 +378,7 @@ Q_DECL_UNUSED Q_DECL_COLD_FUNCTION stati
     switch (r.machine) {
     // list definitely not exhaustive!
     case EM_NONE:       d << ", no machine"; break;
+    case EM_ALPHA:      d << ", ALPHA"; break;
     case EM_ARM:        d << ", ARM"; break;
     case EM_AARCH64:    d << ", AArch64"; break;
 #ifdef EM_BLACKFIN
