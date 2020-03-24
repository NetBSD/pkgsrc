$NetBSD: patch-dnssd_servicemodel.cpp,v 1.1 2020/03/24 20:34:31 joerg Exp $

--- dnssd/servicemodel.cpp.orig	2020-03-23 22:23:18.729772347 +0000
+++ dnssd/servicemodel.cpp
@@ -87,7 +87,7 @@ QVariant ServiceModel::data(const QModel
 		case Host: return srv[index.row()]->hostName();
 		case Port: return srv[index.row()]->port();
 	    }
-	case ServicePtrRole: QVariant ret;
+	case (int)ServicePtrRole: QVariant ret;
 			     ret.setValue(srv[index.row()]);
 			    return ret;
     }
