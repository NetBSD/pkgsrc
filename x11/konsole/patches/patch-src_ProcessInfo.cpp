$NetBSD: patch-src_ProcessInfo.cpp,v 1.1.1.1 2012/03/20 05:07:49 markd Exp $

--- src/ProcessInfo.cpp.orig	2010-03-26 17:26:32.000000000 +0000
+++ src/ProcessInfo.cpp
@@ -894,6 +894,171 @@ private:
     }
 } ;
 
+class NetBSDProcessInfo : public UnixProcessInfo
+{
+public:
+    NetBSDProcessInfo(int pid, bool env) :
+        UnixProcessInfo(pid,env)
+    {
+    }
+
+private:
+    virtual bool readProcInfo(int pid)
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
+        QFile processInfo( QString("/proc/%1/status").arg(pid) );
+        if ( processInfo.open(QIODevice::ReadOnly) )
+        {
+            QTextStream stream(&processInfo);
+            QString data = stream.readAll();
+
+            int stack = 0;
+            int field = 0;
+            int pos = 0;
+
+            while (pos < data.count())
+            {
+                QChar c = data[pos];
+
+                if ( c == '(' )
+                    stack++;
+                else if ( c == ')' )
+                    stack--;
+                else if ( stack == 0 && c == ' ' )
+                    field++;
+                else
+                {
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
+        setPid(pid);
+
+        return ok;
+    }
+
+    virtual bool readArguments(int pid)
+    {
+        // read command-line arguments file found at /proc/<pid>/cmdline
+        // the expected format is a list of strings delimited by null characters,
+        // and ending in a double null character pair.
+
+        QFile argumentsFile( QString("/proc/%1/cmdline").arg(pid) );
+        if ( argumentsFile.open(QIODevice::ReadOnly) )
+        {
+            QTextStream stream(&argumentsFile);
+            QString data = stream.readAll();
+
+            QStringList argList = data.split( QChar('\0') );
+
+            foreach ( const QString &entry , argList )
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
+    virtual bool readCurrentDir(int pid)
+    {
+        QFileInfo info( QString("/proc/%1/cwd").arg(pid) );
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
+
+    virtual bool readEnvironment(int pid)
+    {
+        // Not supported in NetBSD
+        return true;
+    }
+} ;
+
 SSHProcessInfo::SSHProcessInfo(const ProcessInfo& process)
  : _process(process)
 {
@@ -1039,6 +1204,8 @@ ProcessInfo* ProcessInfo::newInstance(in
     return new LinuxProcessInfo(pid,enableEnvironmentRead);
 #elif defined(Q_OS_SOLARIS)
     return new SolarisProcessInfo(pid,enableEnvironmentRead);
+#elif defined(Q_OS_NETBSD)
+    return new NetBSDProcessInfo(pid,enableEnvironmentRead);
 #elif defined(Q_OS_MAC)
     return new MacProcessInfo(pid,enableEnvironmentRead);
 #elif defined(Q_OS_FREEBSD)
