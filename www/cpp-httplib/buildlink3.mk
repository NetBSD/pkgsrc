# $NetBSD: buildlink3.mk,v 1.1 2024/05/19 15:45:48 wiz Exp $

BUILDLINK_TREE+=	cpp-httplib

.if !defined(CPP_HTTPLIB_BUILDLINK3_MK)
CPP_HTTPLIB_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.cpp-httplib?=	build

BUILDLINK_API_DEPENDS.cpp-httplib+=	cpp-httplib>=0.15.3
BUILDLINK_PKGSRCDIR.cpp-httplib?=	../../www/cpp-httplib
.endif	# CPP_HTTPLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cpp-httplib
