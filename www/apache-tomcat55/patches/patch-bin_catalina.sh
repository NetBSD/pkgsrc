$NetBSD: patch-bin_catalina.sh,v 1.1 2024/07/18 12:52:23 ryoon Exp $

* -Djava.endorsed.dirs is invalid for openjdk9 or later.
  Fix invocation.

--- bin/catalina.sh.orig	2024-07-18 12:46:12.815521328 +0000
+++ bin/catalina.sh
@@ -238,7 +238,7 @@ if [ "$1" = "debug" ] ; then
       fi
       shift
       exec "$_RUNJDB" "$LOGGING_CONFIG" $JAVA_OPTS  $CATALINA_OPTS \
-        -Djava.endorsed.dirs="$JAVA_ENDORSED_DIRS" -classpath "$CLASSPATH" \
+        -classpath "$CLASSPATH" \
         -sourcepath "$CATALINA_HOME"/../../jakarta-tomcat-catalina/catalina/src/share \
         -Djava.security.manager \
         -Djava.security.policy=="$CATALINA_BASE"/conf/catalina.policy \
@@ -248,7 +248,7 @@ if [ "$1" = "debug" ] ; then
         org.apache.catalina.startup.Bootstrap "$@" start
     else
       exec "$_RUNJDB" "$LOGGING_CONFIG" $JAVA_OPTS  $CATALINA_OPTS \
-        -Djava.endorsed.dirs="$JAVA_ENDORSED_DIRS" -classpath "$CLASSPATH" \
+        -classpath "$CLASSPATH" \
         -sourcepath "$CATALINA_HOME"/../../jakarta-tomcat-catalina/catalina/src/share \
         -Dcatalina.base="$CATALINA_BASE" \
         -Dcatalina.home="$CATALINA_HOME" \
@@ -266,7 +266,7 @@ elif [ "$1" = "run" ]; then
     fi
     shift
     exec "$_RUNJAVA" "$LOGGING_CONFIG" $JAVA_OPTS  $CATALINA_OPTS \
-      -Djava.endorsed.dirs="$JAVA_ENDORSED_DIRS" -classpath "$CLASSPATH" \
+      -classpath "$CLASSPATH" \
       -Djava.security.manager \
       -Djava.security.policy=="$CATALINA_BASE"/conf/catalina.policy \
       -Dcatalina.base="$CATALINA_BASE" \
@@ -275,7 +275,7 @@ elif [ "$1" = "run" ]; then
       org.apache.catalina.startup.Bootstrap "$@" start
   else
     exec "$_RUNJAVA" "$LOGGING_CONFIG" $JAVA_OPTS  $CATALINA_OPTS \
-      -Djava.endorsed.dirs="$JAVA_ENDORSED_DIRS" -classpath "$CLASSPATH" \
+      -classpath "$CLASSPATH" \
       -Dcatalina.base="$CATALINA_BASE" \
       -Dcatalina.home="$CATALINA_HOME" \
       -Djava.io.tmpdir="$CATALINA_TMPDIR" \
@@ -292,7 +292,7 @@ elif [ "$1" = "start" ] ; then
     fi
     shift
     "$_RUNJAVA" "$LOGGING_CONFIG" $JAVA_OPTS  $CATALINA_OPTS \
-      -Djava.endorsed.dirs="$JAVA_ENDORSED_DIRS" -classpath "$CLASSPATH" \
+      -classpath "$CLASSPATH" \
       -Djava.security.manager \
       -Djava.security.policy=="$CATALINA_BASE"/conf/catalina.policy \
       -Dcatalina.base="$CATALINA_BASE" \
@@ -306,7 +306,7 @@ elif [ "$1" = "start" ] ; then
       fi
   else
     "$_RUNJAVA" "$LOGGING_CONFIG" $JAVA_OPTS  $CATALINA_OPTS \
-      -Djava.endorsed.dirs="$JAVA_ENDORSED_DIRS" -classpath "$CLASSPATH" \
+      -classpath "$CLASSPATH" \
       -Dcatalina.base="$CATALINA_BASE" \
       -Dcatalina.home="$CATALINA_HOME" \
       -Djava.io.tmpdir="$CATALINA_TMPDIR" \
@@ -328,7 +328,7 @@ elif [ "$1" = "stop" ] ; then
   fi
 
   "$_RUNJAVA" $JAVA_OPTS \
-    -Djava.endorsed.dirs="$JAVA_ENDORSED_DIRS" -classpath "$CLASSPATH" \
+    -classpath "$CLASSPATH" \
     -Dcatalina.base="$CATALINA_BASE" \
     -Dcatalina.home="$CATALINA_HOME" \
     -Djava.io.tmpdir="$CATALINA_TMPDIR" \
