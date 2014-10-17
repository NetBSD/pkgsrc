$NetBSD: patch-mozilla_js_src_builtin_TypedObject.cpp,v 1.1 2014/10/17 16:50:11 joerg Exp $

--- mozilla/js/src/builtin/TypedObject.cpp.orig	2014-06-13 00:46:08.000000000 +0000
+++ mozilla/js/src/builtin/TypedObject.cpp
@@ -753,7 +753,7 @@ ArrayType::construct(JSContext *cx, unsi
     // Extract ArrayType.prototype
     RootedObject arrayTypePrototype(cx, GetPrototype(cx, arrayTypeGlobal));
     if (!arrayTypePrototype)
-        return nullptr;
+        return false;
 
     // Create the instance of ArrayType
     RootedObject obj(
@@ -766,7 +766,7 @@ ArrayType::construct(JSContext *cx, unsi
     if (!JSObject::defineProperty(cx, obj, cx->names().length,
                                   lengthVal, nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
-        return nullptr;
+        return false;
 
     args.rval().setObject(*obj);
     return true;
@@ -814,7 +814,7 @@ ArrayType::dimension(JSContext *cx, unsi
     if (!JSObject::defineProperty(cx, obj, cx->names().length,
                                   lengthVal, nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
-        return nullptr;
+        return false;
 
     // Add `unsized` property, which is a link from the sized
     // array to the unsized array.
@@ -822,7 +822,7 @@ ArrayType::dimension(JSContext *cx, unsi
     if (!JSObject::defineProperty(cx, obj, cx->names().unsized,
                                   unsizedTypeObjValue, nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
-        return nullptr;
+        return false;
 
     args.rval().setObject(*obj);
     return true;
@@ -1244,14 +1244,14 @@ GlobalObject::initTypedObjectModule(JSCo
 #define BINARYDATA_SCALAR_DEFINE(constant_, type_, name_)                       \
     if (!DefineSimpleTypeObject<ScalarType>(cx, global, module, constant_,      \
                                             cx->names().name_))                 \
-        return nullptr;
+        return false;
     JS_FOR_EACH_SCALAR_TYPE_REPR(BINARYDATA_SCALAR_DEFINE)
 #undef BINARYDATA_SCALAR_DEFINE
 
 #define BINARYDATA_REFERENCE_DEFINE(constant_, type_, name_)                    \
     if (!DefineSimpleTypeObject<ReferenceType>(cx, global, module, constant_,   \
                                                cx->names().name_))              \
-        return nullptr;
+        return false;
     JS_FOR_EACH_REFERENCE_TYPE_REPR(BINARYDATA_REFERENCE_DEFINE)
 #undef BINARYDATA_REFERENCE_DEFINE
 
@@ -1261,14 +1261,14 @@ GlobalObject::initTypedObjectModule(JSCo
     arrayType = DefineMetaTypeObject<ArrayType>(
         cx, global, module, TypedObjectModuleObject::ArrayTypePrototype);
     if (!arrayType)
-        return nullptr;
+        return false;
 
     RootedValue arrayTypeValue(cx, ObjectValue(*arrayType));
     if (!JSObject::defineProperty(cx, module, cx->names().ArrayType,
                                   arrayTypeValue,
                                   nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
-        return nullptr;
+        return false;
 
     // StructType.
 
@@ -1276,23 +1276,23 @@ GlobalObject::initTypedObjectModule(JSCo
     structType = DefineMetaTypeObject<StructType>(
         cx, global, module, TypedObjectModuleObject::StructTypePrototype);
     if (!structType)
-        return nullptr;
+        return false;
 
     RootedValue structTypeValue(cx, ObjectValue(*structType));
     if (!JSObject::defineProperty(cx, module, cx->names().StructType,
                                   structTypeValue,
                                   nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
-        return nullptr;
+        return false;
 
     //  Handle
 
     RootedObject handle(cx, NewBuiltinClassInstance(cx, &JSObject::class_));
     if (!module)
-        return nullptr;
+        return false;
 
     if (!JS_DefineFunctions(cx, handle, TypedHandle::handleStaticMethods))
-        return nullptr;
+        return false;
 
     RootedValue handleValue(cx, ObjectValue(*handle));
     if (!JSObject::defineProperty(cx, module, cx->names().Handle,
@@ -1300,7 +1300,7 @@ GlobalObject::initTypedObjectModule(JSCo
                                   nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
     {
-        return nullptr;
+        return false;
     }
 
     // Everything is setup, install module on the global object:
@@ -1311,10 +1311,10 @@ GlobalObject::initTypedObjectModule(JSCo
                                   nullptr, nullptr,
                                   0))
     {
-        return nullptr;
+        return false;
     }
 
-    return module;
+    return module != nullptr;
 }
 
 JSObject *
@@ -2404,7 +2404,7 @@ TypedObject::construct(JSContext *cx, un
     // Create zeroed wrapper object.
     Rooted<TypedObject*> obj(cx, createZeroed(cx, callee, length));
     if (!obj)
-        return nullptr;
+        return false;
 
     if (nextArg < argc) {
         RootedValue initial(cx, args[nextArg++]);
