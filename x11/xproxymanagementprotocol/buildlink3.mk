# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:36 rodent Exp $

BUILDLINK_TREE+=	xproxymanagementprotocol

.if !defined(XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK)
XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xproxymanagementprotocol?=	build

BUILDLINK_API_DEPENDS.xproxymanagementprotocol+=	xproxymanagementprotocol>=1.0.2
BUILDLINK_PKGSRCDIR.xproxymanagementprotocol?=	../../x11/xproxymanagementprotocol
.endif # XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xproxymanagementprotocol
