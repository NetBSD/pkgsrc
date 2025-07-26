$NetBSD: patch-gfx_skia_skia_src_sksl_codegen_SkSLSPIRVCodeGenerator.cpp,v 1.1 2025/07/26 14:12:54 ryoon Exp $

--- gfx/skia/skia/src/sksl/codegen/SkSLSPIRVCodeGenerator.cpp.orig	2025-07-26 13:25:51.000473818 +0000
+++ gfx/skia/skia/src/sksl/codegen/SkSLSPIRVCodeGenerator.cpp
@@ -4405,7 +4405,7 @@ void SPIRVCodeGenerator::writeFunctionSt
             f, fSpecializationInfo, fActiveSpecializationIndex,
             [&](int, const Variable*, const Expression* expr) {
                 std::string name = expr->description();
-                std::replace_if(name.begin(), name.end(), [](char c) { return !isalnum(c); }, '_');
+                std::replace_if(name.begin(), name.end(), [](char c) { return !isalnum(i(unsigned char)c); }, '_');
 
                 mangledName += "_" + name;
             });
