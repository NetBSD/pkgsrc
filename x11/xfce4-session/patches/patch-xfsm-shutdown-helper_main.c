$NetBSD: patch-xfsm-shutdown-helper_main.c,v 1.5 2025/01/06 19:27:40 bsiegert Exp $

Be careful to only SUSPEND or HIBERNATE when defined.

--- xfsm-shutdown-helper/main.c.orig	2024-10-11 05:36:33.000000000 +0000
+++ xfsm-shutdown-helper/main.c
@@ -183,22 +183,26 @@ main (int argc, char **argv)
     }
   else if (suspend)
     {
+#if defined(UP_BACKEND_SUSPEND_COMMAND)
       if (run (UP_BACKEND_SUSPEND_COMMAND))
         {
           return EXIT_CODE_SUCCESS;
         }
       else
+#endif
         {
           return EXIT_CODE_FAILED;
         }
     }
   else if (hibernate)
     {
+#if defined (UP_BACKEND_HIBERNATE_COMMAND)
       if (run (UP_BACKEND_HIBERNATE_COMMAND))
         {
           return EXIT_CODE_SUCCESS;
         }
       else
+#endif
         {
           return EXIT_CODE_FAILED;
         }
