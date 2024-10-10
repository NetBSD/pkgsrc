$NetBSD: patch-args.c,v 1.1 2024/10/10 17:16:46 nia Exp $

Use standard type.

--- args.c.orig	2024-10-10 17:14:12.156455437 +0000
+++ args.c
@@ -74,7 +74,7 @@ static void apply_value_to_arg(struct ar
 		*((int*)arg->value) = !strncmp(value, "--no-", 5) ? 0 : 1;
 		break;
 	case ARGT_SET_BIT:
-		*((uint*)arg->value) |= arg->def.b;
+		*((unsigned int*)arg->value) |= arg->def.b;
 		break;
 	case ARGT_SET_INT:
 		*((int*)arg->value) = arg->def.i;
