$NetBSD: patch-mozilla_ipc_ipdl_ipdl_lower.py,v 1.1 2013/01/20 08:33:14 ryoon Exp $

--- mozilla/ipc/ipdl/ipdl/lower.py.orig	2013-01-06 06:26:17.000000000 +0000
+++ mozilla/ipc/ipdl/ipdl/lower.py
@@ -1797,7 +1797,7 @@ def _generateMessageClass(clsname, msgid
         StmtExpr(ExprCall(
             ExprVar('StringAppendF'),
             args=[ ExprAddrOf(msgvar),
-                   ExprLiteral.String('[time:%" PRId64 "][%d]'),
+                   ExprLiteral.String('[time:%\\" PRId64 \\"][%d]'),
                    ExprCall(ExprVar('PR_Now')),
                    ExprCall(ExprVar('base::GetCurrentProcId')) ])),
         appendToMsg(pfxvar),
