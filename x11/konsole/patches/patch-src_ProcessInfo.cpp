$NetBSD: patch-src_ProcessInfo.cpp,v 1.7 2025/12/21 20:19:56 markd Exp $

NetBSD support and QT fixes.

--- src/ProcessInfo.cpp.orig	2025-10-31 21:34:06.000000000 +0000
+++ src/ProcessInfo.cpp
@@ -889,6 +889,227 @@ private:
     }
 };
 
+#elif defined(Q_OS_NETBSD)
+class NetBSDProcessInfo : public UnixProcessInfo
+{
+public:
+    explicit NetBSDProcessInfo(int pid)
+        : UnixProcessInfo(pid)
+    {
+    }
+
+private:
+    bool readProcessName(int aPid) override
+    {
+        // indicies of various fields within the process status file which
+        // contain various information about the process
+        const int PROCESS_NAME_FIELD = 0;
+
+        QString processNameString;
+
+        // read process status file ( /proc/<pid/status )
+        //
+        // the expected file format is a list of fields separated by spaces, using
+        // parenthesies to escape fields such as the process name which may itself contain
+        // spaces:
+        //
+        // FIELD FIELD (FIELD WITH SPACES) FIELD FIELD
+        //
+        QFile processInfo( QStringLiteral("/proc/%1/status").arg(aPid) );
+        if ( processInfo.open(QIODevice::ReadOnly) )
+        {
+           QTextStream stream(&processInfo);
+            QString data = stream.readAll();
+
+            int stack = 0;
+            int field = 0;
+            int pos = 0;
+
+            while (pos < data.count()) {
+                QChar c = data[pos];
+
+                if ( c == QLatin1Char('(')) {
+                    stack++;
+                } else if ( c == QLatin1Char(')')) {
+                    stack--;
+                } else if ( stack == 0 && c == QLatin1Char(' ')) {
+                    field++;
+                } else {
+                    switch ( field )
+                    {
+                        case PROCESS_NAME_FIELD:
+                            processNameString.append(c);
+                            break;
+                    }
+                }
+
+                pos++;
+            }
+        }
+        else
+        {
+            setFileError( processInfo.error() );
+            return false;
+        }
+
+        // check that data was read successfully
+        bool ok = false;
+
+        if (!processNameString.isEmpty())
+            setName(processNameString);
+
+        return ok;
+    }
+
+private:
+    bool readProcInfo(int aPid) override
+    {
+        // indicies of various fields within the process status file which
+        // contain various information about the process
+        const int PARENT_PID_FIELD = 2;
+        const int PROCESS_NAME_FIELD = 0;
+        const int GROUP_PROCESS_FIELD = 3;
+        const int UID_PROCESS_FIELD = 11;
+
+        QString parentPidString;
+        QString processNameString;
+        QString foregroundPidString;
+        QString uidString;
+
+        // read process status file ( /proc/<pid/status )
+        //
+        // the expected file format is a list of fields separated by spaces, using
+        // parenthesies to escape fields such as the process name which may itself contain
+        // spaces:
+        //
+        // FIELD FIELD (FIELD WITH SPACES) FIELD FIELD
+        //
+        QFile processInfo( QStringLiteral("/proc/%1/status").arg(aPid) );
+        if ( processInfo.open(QIODevice::ReadOnly) )
+        {
+            QTextStream stream(&processInfo);
+            QString data = stream.readAll();
+
+            int stack = 0;
+            int field = 0;
+            int pos = 0;
+
+            while (pos < data.count()) {
+                QChar c = data[pos];
+
+                if ( c == QLatin1Char('(')) {
+                    stack++;
+                } else if ( c == QLatin1Char(')')) {
+                    stack--;
+                } else if ( stack == 0 && c == QLatin1Char(' ')) {
+                    field++;
+                } else {
+                    switch ( field )
+                    {
+                        case PARENT_PID_FIELD:
+                            parentPidString.append(c);
+                            break;
+                        case PROCESS_NAME_FIELD:
+                            processNameString.append(c);
+                            break;
+                        case GROUP_PROCESS_FIELD:
+                            foregroundPidString.append(c);
+                            break;
+                        case UID_PROCESS_FIELD:
+                            uidString.append(c);
+                            break;
+                    }
+                }
+
+                pos++;
+            }
+        }
+        else
+        {
+            setFileError( processInfo.error() );
+            return false;
+        }
+
+        // check that data was read successfully
+        bool ok = false;
+
+        // uid string must be less than 5 chars (uint)
+        if (uidString.size() > 5)
+            uidString.clear();
+
+        int uid = uidString.toInt(&ok);
+        if (ok)
+            setUserId(uid);
+        readUserName();
+
+        int foregroundPid = foregroundPidString.toInt(&ok);
+        if (ok)
+            setForegroundPid(foregroundPid);
+
+        int parentPid = parentPidString.toInt(&ok);
+        if (ok)
+            setParentPid(parentPid);
+
+        if (!processNameString.isEmpty())
+            setName(processNameString);
+
+        // update object state
+        setPid(aPid);
+
+        return ok;
+    }
+
+    bool readArguments(int aPid) override
+    {
+        // read command-line arguments file found at /proc/<pid>/cmdline
+        // the expected format is a list of strings delimited by null characters,
+        // and ending in a double null character pair.
+
+        QFile argumentsFile( QStringLiteral("/proc/%1/cmdline").arg(aPid) );
+        if ( argumentsFile.open(QIODevice::ReadOnly) )
+        {
+            QTextStream stream(&argumentsFile);
+            const QString &data = stream.readAll();
+
+            const QStringList &argList = data.split( QLatin1Char('\0') );
+
+            for ( const QString &entry : argList )
+            {
+                if (!entry.isEmpty())
+                    addArgument(entry);
+            }
+        }
+        else
+        {
+            setFileError( argumentsFile.error() );
+        }
+
+        return true;
+    }
+
+    bool readCurrentDir(int aPid) override
+    {
+        QFileInfo info( QStringLiteral("/proc/%1/cwd").arg(aPid) );
+
+        const bool readable = info.isReadable();
+
+        if ( readable && info.isSymLink() )
+        {
+            setCurrentDir( info.symLinkTarget() );
+            return true;
+        }
+        else
+        {
+            if ( !readable )
+                setError( PermissionsError );
+            else
+                setError( UnknownError );
+
+            return false;
+        }
+    }
+};
+
 #elif defined(Q_OS_OPENBSD)
 class OpenBSDProcessInfo : public UnixProcessInfo
 {
@@ -1214,7 +1435,7 @@ protected:
     // version uses readlink.
     bool readCurrentDir(int pid) override
     {
-        QFileInfo info(QString("/proc/%1/path/cwd").arg(pid));
+        QFileInfo info(QStringLiteral("/proc/%1/path/cwd").arg(pid));
         const bool readable = info.isReadable();
 
         if (readable && info.isSymLink()) {
@@ -1244,7 +1465,7 @@ protected:
 private:
     bool readProcInfo(int pid) override
     {
-        QFile psinfo(QString("/proc/%1/psinfo").arg(pid));
+        QFile psinfo(QStringLiteral("/proc/%1/psinfo").arg(pid));
         if (psinfo.open(QIODevice::ReadOnly)) {
             struct psinfo info;
             if (psinfo.read((char *)&info, sizeof(info)) != sizeof(info)) {
@@ -1253,12 +1474,13 @@ private:
 
             setParentPid(info.pr_ppid);
             setForegroundPid(info.pr_pgid);
-            setName(info.pr_fname);
+            //setName(info.pr_fname);
+            setName(QString::fromUtf8(info.pr_fname));
             setPid(pid);
 
             // Bogus, because we're treating the arguments as one single string
             info.pr_psargs[PRARGSZ - 1] = 0;
-            addArgument(info.pr_psargs);
+            addArgument(QString::fromUtf8(info.pr_psargs));
         }
 
         _execNameFile = std::make_unique(new QFile());
@@ -1283,6 +1505,8 @@ ProcessInfo *ProcessInfo::newInstance(in
     info = new MacProcessInfo(pid);
 #elif defined(Q_OS_FREEBSD)
     info = new FreeBSDProcessInfo(pid);
+#elif defined(Q_OS_NETBSD)
+    info = new NetBSDProcessInfo(pid);
 #elif defined(Q_OS_OPENBSD)
     info = new OpenBSDProcessInfo(pid);
 #else
