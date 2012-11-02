$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_interpreter_Interpreter.cpp,v 1.1 2012/11/02 22:30:31 joerg Exp $

--- src/3rdparty/javascriptcore/JavaScriptCore/interpreter/Interpreter.cpp.orig	2012-11-02 10:51:13.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/interpreter/Interpreter.cpp
@@ -2493,8 +2493,10 @@ JSValue Interpreter::privateExecute(Exec
             vPC += OPCODE_LENGTH(op_get_by_pname);
             NEXT_INSTRUCTION();
         }
+        {
         Identifier propertyName(callFrame, subscript.toString(callFrame));
         result = baseValue.get(callFrame, propertyName);
+        }
         CHECK_FOR_EXCEPTION();
         callFrame->r(dst) = result;
         vPC += OPCODE_LENGTH(op_get_by_pname);
