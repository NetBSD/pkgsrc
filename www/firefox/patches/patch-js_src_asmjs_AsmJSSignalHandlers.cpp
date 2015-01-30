$NetBSD: patch-js_src_asmjs_AsmJSSignalHandlers.cpp,v 1.1 2015/01/30 07:32:24 pho Exp $

Increase portability for non-x86 Darwin by not hardwiring
x86_THREAD_STATE.

--- js/src/asmjs/AsmJSSignalHandlers.cpp.orig	2015-01-29 00:54:07.000000000 +0000
+++ js/src/asmjs/AsmJSSignalHandlers.cpp
@@ -524,17 +524,62 @@ AsmJSExceptionHandler(LPEXCEPTION_POINTE
 #elif defined(XP_MACOSX)
 # include <mach/exc.h>
 
+# if defined(ARM_THREAD_STATE)
+typedef arm_thread_state_t moz_platform_thread_state_t;
+static const thread_state_flavor_t  MOZ_PLATFORM_THREAD_STATE_FLAVOR = ARM_THREAD_STATE;
+static const mach_msg_type_number_t MOZ_PLATFORM_THREAD_STATE_COUNT  = ARM_THREAD_STATE_COUNT;
+
+# elif defined(PPC_THREAD_STATE)
+typedef ppc_thread_state_t moz_platform_thread_state_t;
+static const thread_state_flavor_t  MOZ_PLATFORM_THREAD_STATE_FLAVOR = PPC_THREAD_STATE;
+static const mach_msg_type_number_t MOZ_PLATFORM_THREAD_STATE_COUNT  = PPC_THREAD_STATE_COUNT;
+
+# elif defined(PPC_THREAD_STATE64)
+typedef ppc_thread_state64_t moz_platform_thread_state_t;
+static const thread_state_flavor_t  MOZ_PLATFORM_THREAD_STATE_FLAVOR = PPC_THREAD_STATE64;
+static const mach_msg_type_number_t MOZ_PLATFORM_THREAD_STATE_COUNT  = PPC_THREAD_STATE64_COUNT;
+
+# elif defined(x86_THREAD_STATE)
+typedef x86_thread_state_t moz_platform_thread_state_t;
+static const thread_state_flavor_t  MOZ_PLATFORM_THREAD_STATE_FLAVOR = x86_THREAD_STATE;
+static const mach_msg_type_number_t MOZ_PLATFORM_THREAD_STATE_COUNT  = x86_THREAD_STATE_COUNT;
+
+# else
+#  error Type unknown for platform-specific thread_state_t
+# endif
+
+# if defined(__DARWIN_UNIX03)
+#  define REG_FIELD(NAME) __ ## NAME
+# else
+#  define REG_FIELD(NAME) NAME
+# endif
+
 static uint8_t **
-ContextToPC(x86_thread_state_t &state)
+ContextToPC(moz_platform_thread_state_t &state)
 {
-# if defined(JS_CODEGEN_X64)
-    JS_STATIC_ASSERT(sizeof(state.uts.ts64.__rip) == sizeof(void*));
-    return reinterpret_cast<uint8_t**>(&state.uts.ts64.__rip);
-# elif defined(JS_CODEGEN_NONE)
-    MOZ_CRASH();
+#if defined(ARM_THREAD_STATE)
+    JS_STATIC_ASSERT(sizeof(state.REG_FIELD(pc)) == sizeof(void*));
+    return reinterpret_cast<uint8_t**>(&state.REG_FIELD(pc));
+
+#elif defined(PPC_THREAD_STATE) || defined(PPC_THREAD_STATE64)
+    JS_STATIC_ASSERT(sizeof(state.REG_FIELD(srr0)) == sizeof(void*));
+    return reinterpret_cast<uint8_t**>(&state.REG_FIELD(srr0));
+
+#elif defined(x86_THREAD_STATE)
+    switch (state.tsh.flavor) {
+    case x86_THREAD_STATE32:
+        JS_STATIC_ASSERT(sizeof(state.uts.ts32.REG_FIELD(eip)) == sizeof(void*));
+        return reinterpret_cast<uint8_t**>(&state.uts.ts32.REG_FIELD(eip));
+
+    case x86_THREAD_STATE64:
+        JS_STATIC_ASSERT(sizeof(state.uts.ts64.REG_FIELD(rip)) == sizeof(void*));
+        return reinterpret_cast<uint8_t**>(&state.uts.ts64.REG_FIELD(rip));
+
+    default:
+        MOZ_CRASH("Unknown thread state flavor");
+    }
 # else
-    JS_STATIC_ASSERT(sizeof(state.uts.ts32.__eip) == sizeof(void*));
-    return reinterpret_cast<uint8_t**>(&state.uts.ts32.__eip);
+#  error Instruction address register unknown for this platform
 # endif
 }
 
@@ -637,10 +682,11 @@ HandleMachException(JSRuntime *rt, const
     mach_port_t rtThread = request.body.thread.name;
 
     // Read out the JSRuntime thread's register state.
-    x86_thread_state_t state;
-    unsigned int count = x86_THREAD_STATE_COUNT;
+    moz_platform_thread_state_t state;
+    thread_state_flavor_t flavor = MOZ_PLATFORM_THREAD_STATE_FLAVOR;
+    mach_msg_type_number_t count = MOZ_PLATFORM_THREAD_STATE_COUNT;
     kern_return_t kret;
-    kret = thread_get_state(rtThread, x86_THREAD_STATE, (thread_state_t)&state, &count);
+    kret = thread_get_state(rtThread, flavor, (thread_state_t)&state, &count);
     if (kret != KERN_SUCCESS)
         return false;
 
@@ -682,7 +728,7 @@ HandleMachException(JSRuntime *rt, const
         module.unprotectCode(rt);
 
         // Update the thread state with the new pc.
-        kret = thread_set_state(rtThread, x86_THREAD_STATE, (thread_state_t)&state, x86_THREAD_STATE_COUNT);
+        kret = thread_set_state(rtThread, flavor, (thread_state_t)&state, count);
         return kret == KERN_SUCCESS;
     }
 
