#!/bin/sh
@JAVA_HOME@/bin/java -cp @PREFIX@/lib/cardboard-schedule/stage/cs.jar:@PREFIX@/lib/cardboard-schedule/stage/CsHelp.jar:@PREFIX@/lib/cardboard-schedule/stage/jhbasic.jar:@LOCALBASE@/lib/java/swingall.jar:${CLASSPATH} avg.cs.gui.CsMainApp
