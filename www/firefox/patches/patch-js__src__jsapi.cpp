$NetBSD: patch-js__src__jsapi.cpp,v 1.1 2013/06/21 23:11:42 ryoon Exp $

From bugzilla, bug 840242, attachment v1
Use the runtime page size to control arena decommit.

As a side effect, this removes the hard coded page-size == 4k requirement.


diff js/src/jsapi.cpp js/src/jsapi.cpp
--- js/src/jsapi.cpp
+++ js/src/jsapi.cpp
@@ -1138,18 +1138,16 @@ JS_NewRuntime(uint32_t maxbytes, JSUseHe
                 ++numfmtspecs;                                                \
         }                                                                     \
         JS_ASSERT(count == numfmtspecs);                                      \
     JS_END_MACRO;
 #include "js.msg"
 #undef MSG_DEF
 #endif /* DEBUG */
 
-        InitMemorySubsystem();
-
         if (!js::TlsPerThreadData.init())
             return NULL;
 
         js_NewRuntimeWasCalled = JS_TRUE;
     }
 
     JSRuntime *rt = js_new<JSRuntime>(useHelperThreads);
     if (!rt)
