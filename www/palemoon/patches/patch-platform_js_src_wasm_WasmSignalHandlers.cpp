$NetBSD: patch-platform_js_src_wasm_WasmSignalHandlers.cpp,v 1.1 2026/08/08 11:59:00 nia Exp $

Fix build on newer NetBSD versions.

PR kern/60539 XSAVE changes break ucontext userspace API

--- platform/js/src/wasm/WasmSignalHandlers.cpp.orig	2026-07-28 13:51:54.000000000 +0000
+++ platform/js/src/wasm/WasmSignalHandlers.cpp
@@ -174,7 +174,7 @@ class AutoSetHandlingSegFault
 #  define RFP_sig(p) ((p)->uc_mcontext.__gregs[22])
 # endif
 #elif defined(__NetBSD__)
-# define XMM_sig(p,i) (((struct fxsave64*)(p)->uc_mcontext.__fpregs)->fx_xmm[i])
+# define XMM_sig(p,i) (((struct fxsave64*)&(p)->uc_mcontext.__fpregs)->fx_xmm[i])
 # define EIP_sig(p) ((p)->uc_mcontext.__gregs[_REG_EIP])
 # define RIP_sig(p) ((p)->uc_mcontext.__gregs[_REG_RIP])
 # define RAX_sig(p) ((p)->uc_mcontext.__gregs[_REG_RAX])
