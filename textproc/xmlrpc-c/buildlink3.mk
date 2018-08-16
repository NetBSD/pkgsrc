# $NetBSD: buildlink3.mk,v 1.20 2018/08/16 18:54:32 adam Exp $

BUILDLINK_TREE+=	xmlrpc-c

.if !defined(XMLRPC_C_BUILDLINK3_MK)
XMLRPC_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlrpc-c+=	xmlrpc-c-ss>=1.16.34
BUILDLINK_ABI_DEPENDS.xmlrpc-c+=	xmlrpc-c-ss>=1.25.26nb9
BUILDLINK_PKGSRCDIR.xmlrpc-c?=		../../textproc/xmlrpc-c

.include "../../www/libwww/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # XMLRPC_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmlrpc-c
