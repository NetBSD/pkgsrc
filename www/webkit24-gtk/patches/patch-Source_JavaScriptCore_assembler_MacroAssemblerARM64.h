$NetBSD: patch-Source_JavaScriptCore_assembler_MacroAssemblerARM64.h,v 1.1 2020/08/02 23:32:27 jmcneill Exp $

--- Source/JavaScriptCore/assembler/MacroAssemblerARM64.h.orig	2016-04-10 06:48:36.000000000 +0000
+++ Source/JavaScriptCore/assembler/MacroAssemblerARM64.h
@@ -130,7 +130,6 @@ public:
     // FIXME: Get reasonable implementations for these
     static bool shouldBlindForSpecificArch(uint32_t value) { return value >= 0x00ffffff; }
     static bool shouldBlindForSpecificArch(uint64_t value) { return value >= 0x00ffffff; }
-    static bool shouldBlindForSpecificArch(uintptr_t value) { return value >= 0x00ffffff; }
 
     // Integer operations:
 
