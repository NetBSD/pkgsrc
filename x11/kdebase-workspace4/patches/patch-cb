$NetBSD: patch-cb,v 1.2 2010/10/25 20:55:28 markd Exp $

--- libs/ksysguard/processcore/processes.cpp.orig	2010-06-16 12:02:57.000000000 +0000
+++ libs/ksysguard/processcore/processes.cpp
@@ -206,6 +206,7 @@ bool Processes::updateProcessInfo(Proces
         }
 #endif
         if(d->mUpdateFlags.testFlag(Processes::IOStatistics)) {
+#ifndef Q_OS_NETBSD
             if( d->mHavePreviousIoValues ) {
                 ps->setIoCharactersReadRate((ps->ioCharactersRead - oldIoCharactersRead) * 1000.0 / elapsedTime);
                 ps->setIoCharactersWrittenRate((ps->ioCharactersWritten - oldIoCharactersWritten) * 1000.0 / elapsedTime);
@@ -215,6 +216,7 @@ bool Processes::updateProcessInfo(Proces
                 ps->setIoCharactersActuallyWrittenRate((ps->ioCharactersActuallyWritten - oldIoCharactersActuallyWritten) * 1000.0 / elapsedTime);
             } else
                 d->mHavePreviousIoValues = true;
+#endif
         } else if(d->mHavePreviousIoValues) {
             d->mHavePreviousIoValues = false;
             ps->setIoCharactersReadRate(0);
