# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:55 joerg Exp $

BUILDLINK_DEPMETHOD.xproxymanagementprotocol?=	build

BUILDLINK_TREE+=	xproxymanagementprotocol

.if !defined(XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK)
XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xproxymanagementprotocol+=	xproxymanagementprotocol>=1.0.2
BUILDLINK_PKGSRCDIR.xproxymanagementprotocol?=	../../x11/xproxymanagementprotocol
.endif # XPROXYMANAGEMENTPROTOCOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xproxymanagementprotocol
