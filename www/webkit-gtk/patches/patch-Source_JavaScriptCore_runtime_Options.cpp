$NetBSD: patch-Source_JavaScriptCore_runtime_Options.cpp,v 1.2 2016/01/21 13:42:33 leot Exp $

--- Source/JavaScriptCore/runtime/Options.cpp.orig	2016-01-20 12:13:00.000000000 +0000
+++ Source/JavaScriptCore/runtime/Options.cpp
@@ -610,7 +610,7 @@ bool Option::operator==(const Option& ot
     case Options::Type::unsignedType:
         return m_entry.unsignedVal == other.m_entry.unsignedVal;
     case Options::Type::doubleType:
-        return (m_entry.doubleVal == other.m_entry.doubleVal) || (isnan(m_entry.doubleVal) && isnan(other.m_entry.doubleVal));
+        return (m_entry.doubleVal == other.m_entry.doubleVal) || (std::isnan(m_entry.doubleVal) && std::isnan(other.m_entry.doubleVal));
     case Options::Type::int32Type:
         return m_entry.int32Val == other.m_entry.int32Val;
     case Options::Type::optionRangeType:
