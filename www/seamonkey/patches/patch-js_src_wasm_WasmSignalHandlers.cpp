$NetBSD: patch-js_src_wasm_WasmSignalHandlers.cpp,v 1.1 2026/09/20 18:22:28 wiz Exp $

Fix type error objected to by gcc12, but not gcc10.

--- js/src/wasm/WasmSignalHandlers.cpp.orig	2025-11-15 20:08:14.000000000 +0000
+++ js/src/wasm/WasmSignalHandlers.cpp
@@ -179,7 +179,7 @@ struct AutoSignalHandler
 #  define SP_sig(p) ((p)->uc_mcontext.mc_i7)
 # endif
 #elif defined(__NetBSD__)
-# define XMM_sig(p,i) (((struct fxsave64*)(p)->uc_mcontext.__fpregs)->fx_xmm[i])
+# define XMM_sig(p,i) (((struct fxsave64*)&((p)->uc_mcontext.__fpregs))->fx_xmm[i])
 # define EIP_sig(p) ((p)->uc_mcontext.__gregs[_REG_EIP])
 # define EBP_sig(p) ((p)->uc_mcontext.__gregs[_REG_EBP])
 # define ESP_sig(p) ((p)->uc_mcontext.__gregs[_REG_ESP])
