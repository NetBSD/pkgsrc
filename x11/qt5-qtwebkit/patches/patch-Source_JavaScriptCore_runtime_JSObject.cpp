$NetBSD: patch-Source_JavaScriptCore_runtime_JSObject.cpp,v 1.1 2015/08/30 09:56:45 markd Exp $

Fix g++ 5.0 build

A non-inline template needs to be explicitly instantiated if used
outside the object where it is declared.
QTBUG-44829
--- Source/JavaScriptCore/runtime/JSObject.cpp.orig	2014-12-05 16:24:54.000000000 +0000
+++ Source/JavaScriptCore/runtime/JSObject.cpp
@@ -1909,6 +1909,11 @@ void JSObject::putByIndexBeyondVectorLen
     }
 }
 
+// Used in JSArray.cpp so we must instantiate explicit
+template void JSObject::putByIndexBeyondVectorLengthWithoutAttributes<Int32Shape>(ExecState* exec, unsigned i, JSValue value);
+template void JSObject::putByIndexBeyondVectorLengthWithoutAttributes<DoubleShape>(ExecState* exec, unsigned i, JSValue value);
+template void JSObject::putByIndexBeyondVectorLengthWithoutAttributes<ContiguousShape>(ExecState* exec, unsigned i, JSValue value);
+
 void JSObject::putByIndexBeyondVectorLengthWithArrayStorage(ExecState* exec, unsigned i, JSValue value, bool shouldThrow, ArrayStorage* storage)
 {
     VM& vm = exec->vm();
