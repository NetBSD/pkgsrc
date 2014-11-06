$NetBSD: patch-js_src_builtin_TypedObject.cpp,v 1.1 2014/11/06 12:26:51 joerg Exp $

--- js/src/builtin/TypedObject.cpp.orig	2014-11-05 15:45:47.000000000 +0000
+++ js/src/builtin/TypedObject.cpp
@@ -710,12 +710,12 @@ ArrayMetaTypeDescr::construct(JSContext 
     contents.append(")");
     RootedAtom stringRepr(cx, contents.finishAtom());
     if (!stringRepr)
-        return nullptr;
+        return false;
 
     // Extract ArrayType.prototype
     RootedObject arrayTypePrototype(cx, GetPrototype(cx, arrayTypeGlobal));
     if (!arrayTypePrototype)
-        return nullptr;
+        return false;
 
     // Create the instance of ArrayType
     Rooted<UnsizedArrayTypeDescr *> obj(cx);
@@ -728,7 +728,7 @@ ArrayMetaTypeDescr::construct(JSContext 
     if (!JSObject::defineProperty(cx, obj, cx->names().length,
                                   UndefinedHandleValue, nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
-        return nullptr;
+        return false;
 
     args.rval().setObject(*obj);
     return true;
@@ -762,7 +762,7 @@ UnsizedArrayTypeDescr::dimension(JSConte
     if (!size.isValid()) {
         JS_ReportErrorNumber(cx, js_GetErrorMessage, nullptr,
                              JSMSG_TYPEDOBJECT_TOO_BIG);
-        return nullptr;
+        return false;
     }
 
     // Construct a canonical string `new ArrayType(<elementType>).dimension(N)`:
@@ -775,7 +775,7 @@ UnsizedArrayTypeDescr::dimension(JSConte
     contents.append(")");
     RootedAtom stringRepr(cx, contents.finishAtom());
     if (!stringRepr)
-        return nullptr;
+        return false;
 
     // Create the sized type object.
     Rooted<SizedArrayTypeDescr*> obj(cx);
@@ -793,7 +793,7 @@ UnsizedArrayTypeDescr::dimension(JSConte
     if (!JSObject::defineProperty(cx, obj, cx->names().length,
                                   lengthVal, nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
-        return nullptr;
+        return false;
 
     // Add `unsized` property, which is a link from the sized
     // array to the unsized array.
@@ -801,7 +801,7 @@ UnsizedArrayTypeDescr::dimension(JSConte
     if (!JSObject::defineProperty(cx, obj, cx->names().unsized,
                                   unsizedTypeDescrValue, nullptr, nullptr,
                                   JSPROP_READONLY | JSPROP_PERMANENT))
-        return nullptr;
+        return false;
 
     args.rval().setObject(*obj);
     return true;
@@ -1253,7 +1253,7 @@ DefineSimpleTypeDescr(JSContext *cx,
     Rooted<TypedProto*> proto(cx);
     proto = NewObjectWithProto<TypedProto>(cx, objProto, nullptr, TenuredObject);
     if (!proto)
-        return nullptr;
+        return false;
     proto->initTypeDescrSlot(*descr);
     descr->initReservedSlot(JS_DESCR_SLOT_TYPROTO, ObjectValue(*proto));
 
@@ -1358,14 +1358,14 @@ GlobalObject::initTypedObjectModule(JSCo
 #define BINARYDATA_SCALAR_DEFINE(constant_, type_, name_)                       \
     if (!DefineSimpleTypeDescr<ScalarTypeDescr>(cx, global, module, constant_,      \
                                             cx->names().name_))                 \
-        return nullptr;
+        return false;
     JS_FOR_EACH_SCALAR_TYPE_REPR(BINARYDATA_SCALAR_DEFINE)
 #undef BINARYDATA_SCALAR_DEFINE
 
 #define BINARYDATA_REFERENCE_DEFINE(constant_, type_, name_)                    \
     if (!DefineSimpleTypeDescr<ReferenceTypeDescr>(cx, global, module, constant_,   \
                                                cx->names().name_))              \
-        return nullptr;
+        return false;
     JS_FOR_EACH_REFERENCE_TYPE_REPR(BINARYDATA_REFERENCE_DEFINE)
 #undef BINARYDATA_REFERENCE_DEFINE
 
@@ -1375,14 +1375,14 @@ GlobalObject::initTypedObjectModule(JSCo
     arrayType = DefineMetaTypeDescr<ArrayMetaTypeDescr>(
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
 
@@ -1390,14 +1390,14 @@ GlobalObject::initTypedObjectModule(JSCo
     structType = DefineMetaTypeDescr<StructMetaTypeDescr>(
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
 
     // Everything is setup, install module on the global object:
     RootedValue moduleValue(cx, ObjectValue(*module));
@@ -1407,7 +1407,7 @@ GlobalObject::initTypedObjectModule(JSCo
                                   nullptr, nullptr,
                                   0))
     {
-        return nullptr;
+        return false;
     }
 
     return module;
@@ -2466,7 +2466,7 @@ TypedObject::constructUnsized(JSContext 
         if (length < 0) {
             JS_ReportErrorNumber(cx, js_GetErrorMessage,
                                  nullptr, JSMSG_TYPEDOBJECT_BAD_ARGS);
-            return nullptr;
+            return false;
         }
         Rooted<TypedObject*> obj(cx, createZeroed(cx, callee, length));
         if (!obj)
