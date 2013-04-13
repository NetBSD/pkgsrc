$NetBSD: patch-src_corelib_animation_qpropertyanimation.cpp,v 1.1 2013/04/13 10:29:26 jaapb Exp $

Patch from Qt bug 29082, solving a problem with KDE crashes
--- src/corelib/animation/qpropertyanimation.cpp.orig	2012-11-23 10:09:55.000000000 +0000
+++ src/corelib/animation/qpropertyanimation.cpp
@@ -135,8 +135,11 @@ void QPropertyAnimationPrivate::updatePr
 
     if (newValue.userType() == propertyType) {
         //no conversion is needed, we directly call the QMetaObject::metacall
-        void *data = const_cast<void*>(newValue.constData());
-        QMetaObject::metacall(targetValue, QMetaObject::WriteProperty, propertyIndex, &data);
+        //check QMetaProperty::write for an explanation of these
+        int status = -1;
+        int flags = 0;
+        void *argv[] = { const_cast<void *>(newValue.constData()), const_cast<QVariant *>(&newValue), &status, &flags };
+        QMetaObject::metacall(targetValue, QMetaObject::WriteProperty, propertyIndex, argv);
     } else {
         targetValue->setProperty(propertyName.constData(), newValue);
     }
