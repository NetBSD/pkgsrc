# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:34 joerg Exp $

BUILDLINK_TREE+=	xmlrpc-c

.if !defined(XMLRPC_C_BUILDLINK3_MK)
XMLRPC_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlrpc-c+=	xmlrpc-c>=1.09.00
BUILDLINK_ABI_DEPENDS.xmlrpc-c?=	xmlrpc-c>=1.09.00nb3
BUILDLINK_PKGSRCDIR.xmlrpc-c?=	../../textproc/xmlrpc-c

.include "../../www/libwww/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # XMLRPC_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmlrpc-c
