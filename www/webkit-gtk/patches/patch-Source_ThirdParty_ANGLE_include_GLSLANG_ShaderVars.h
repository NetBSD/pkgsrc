$NetBSD: patch-Source_ThirdParty_ANGLE_include_GLSLANG_ShaderVars.h,v 1.1 2024/08/18 12:08:38 tnn Exp $

Include <cstdint> for uint64_t

--- Source/ThirdParty/ANGLE/include/GLSLANG/ShaderVars.h.orig	2022-06-30 09:49:27.136186400 +0000
+++ Source/ThirdParty/ANGLE/include/GLSLANG/ShaderVars.h
@@ -14,6 +14,7 @@
 #include <array>
 #include <string>
 #include <vector>
+#include <cstdint>
 
 // This type is defined here to simplify ANGLE's integration with glslang for SPIR-V.
 using ShCompileOptions = uint64_t;
