# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/10 13:47:08 joerg Exp $

BUILDLINK_DEPMETHOD.xproxymanagementprotocol?=	build

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK:=	${XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xproxymanagementprotocol
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxproxymanagementprotocol}
BUILDLINK_PACKAGES+=	xproxymanagementprotocol
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xproxymanagementprotocol

.if ${XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xproxymanagementprotocol+=	xproxymanagementprotocol>=1.0.2
BUILDLINK_PKGSRCDIR.xproxymanagementprotocol?=	../../x11/xproxymanagementprotocol
.endif	# XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH:S/+$//}
