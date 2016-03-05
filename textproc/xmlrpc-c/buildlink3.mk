# $NetBSD: buildlink3.mk,v 1.13 2016/03/05 11:27:57 jperkin Exp $

BUILDLINK_TREE+=	xmlrpc-c

.if !defined(XMLRPC_C_BUILDLINK3_MK)
XMLRPC_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlrpc-c+=	xmlrpc-c-ss>=1.16.34
BUILDLINK_ABI_DEPENDS.xmlrpc-c+=	xmlrpc-c-ss>=1.25.26nb2
BUILDLINK_PKGSRCDIR.xmlrpc-c?=	../../textproc/xmlrpc-c

.include "../../www/libwww/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # XMLRPC_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmlrpc-c
