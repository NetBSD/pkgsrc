# $NetBSD: buildlink3.mk,v 1.2 2008/01/18 05:09:46 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XMLRPC_C_BUILDLINK3_MK:=	${XMLRPC_C_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xmlrpc-c
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxmlrpc-c}
BUILDLINK_PACKAGES+=	xmlrpc-c
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xmlrpc-c

.if ${XMLRPC_C_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xmlrpc-c+=	xmlrpc-c>=1.09.00
BUILDLINK_ABI_DEPENDS.xmlrpc-c?=	xmlrpc-c>=1.09.00nb3
BUILDLINK_PKGSRCDIR.xmlrpc-c?=	../../textproc/xmlrpc-c
.endif	# XMLRPC_C_BUILDLINK3_MK

.include "../../www/libwww/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
