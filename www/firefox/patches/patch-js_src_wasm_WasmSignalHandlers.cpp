$NetBSD: patch-js_src_wasm_WasmSignalHandlers.cpp,v 1.1 2018/06/26 09:37:10 jperkin Exp $

Support SunOS.

--- js/src/wasm/WasmSignalHandlers.cpp.orig	2018-06-05 19:47:32.000000000 +0000
+++ js/src/wasm/WasmSignalHandlers.cpp
@@ -135,6 +135,7 @@ struct AutoSignalHandler
 #  define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
 #  define ESP_sig(p) ((p)->uc_mcontext.gregs[REG_ESP])
 # else
+#  include <sys/regset.h>
 #  define XMM_sig(p,i) ((p)->uc_mcontext.fpregs.fp_reg_set.fpchip_state.xmm[i])
 #  define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_PC])
 #  define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
