$NetBSD: patch-js_src_asmjs_AsmJSSignalHandlers.cpp,v 1.2 2015/02/28 04:30:55 ryoon Exp $

Increase portability for non-x86 Darwin by not hardwiring
x86_THREAD_STATE.

--- js/src/asmjs/AsmJSSignalHandlers.cpp.orig	2015-02-17 21:40:38.000000000 +0000
+++ js/src/asmjs/AsmJSSignalHandlers.cpp
@@ -504,8 +504,38 @@ AsmJSFaultHandler(LPEXCEPTION_POINTERS e
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
 # if defined(JS_CPU_X64)
     static_assert(sizeof(state.uts.ts64.__rip) == sizeof(void*),
@@ -617,10 +647,11 @@ HandleMachException(JSRuntime *rt, const
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
 
