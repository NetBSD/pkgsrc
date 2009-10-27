# $NetBSD: buildlink3.mk,v 1.4 2009/10/27 18:50:39 drochner Exp $

BUILDLINK_TREE+=	xmlrpc-c

.if !defined(XMLRPC_C_BUILDLINK3_MK)
XMLRPC_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlrpc-c+=	xmlrpc-c>=1.06.32
BUILDLINK_ABI_DEPENDS.xmlrpc-c?=	xmlrpc-c>=1.06.32
BUILDLINK_PKGSRCDIR.xmlrpc-c?=	../../textproc/xmlrpc-c

.include "../../www/libwww/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # XMLRPC_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmlrpc-c
