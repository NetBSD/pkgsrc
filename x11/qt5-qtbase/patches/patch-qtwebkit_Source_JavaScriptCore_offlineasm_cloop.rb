$NetBSD: patch-qtwebkit_Source_JavaScriptCore_offlineasm_cloop.rb,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* When JIT is disabled, fix build

--- qtwebkit/Source/JavaScriptCore/offlineasm/cloop.rb.orig	2013-11-27 01:01:49.000000000 +0000
+++ qtwebkit/Source/JavaScriptCore/offlineasm/cloop.rb
@@ -398,7 +398,7 @@ def cloopEmitUnaryOperation(operands, ty
 end
 
 def cloopEmitCompareDoubleWithNaNCheckAndBranch(operands, condition)
-    $asm.putc "if (std::isnan(#{operands[0].clValue(:double)}) || isnan(#{operands[1].clValue(:double)})"
+    $asm.putc "if (std::isnan(#{operands[0].clValue(:double)}) || std::isnan(#{operands[1].clValue(:double)})"
     $asm.putc "    || (#{operands[0].clValue(:double)} #{condition} #{operands[1].clValue(:double)}))"
     $asm.putc "    goto #{operands[2].cLabel};"
 end
