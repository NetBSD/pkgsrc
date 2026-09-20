$NetBSD: patch-js_src_wasm_WasmSignalHandlers.cpp,v 1.1 2026/09/20 17:21:58 wiz Exp $

Fix type error objected to by gcc12, but not gcc10.

--- js/src/wasm/WasmSignalHandlers.cpp.orig	2017-05-19 20:28:41.000000000 +0000
+++ js/src/wasm/WasmSignalHandlers.cpp
@@ -168,7 +168,7 @@ class AutoSetHandlingSegFault
 #  define RFP_sig(p) ((p)->uc_mcontext.gregs[30])
 # endif
 #elif defined(__NetBSD__)
-# define XMM_sig(p,i) (((struct fxsave64*)(p)->uc_mcontext.__fpregs)->fx_xmm[i])
+# define XMM_sig(p,i) (((struct fxsave64*)&((p)->uc_mcontext.__fpregs))->fx_xmm[i])
 # define EIP_sig(p) ((p)->uc_mcontext.__gregs[_REG_EIP])
 # define RIP_sig(p) ((p)->uc_mcontext.__gregs[_REG_RIP])
 # define RAX_sig(p) ((p)->uc_mcontext.__gregs[_REG_RAX])
