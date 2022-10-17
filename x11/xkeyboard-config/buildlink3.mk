# $NetBSD: buildlink3.mk,v 1.3 2022/10/17 07:45:28 wiz Exp $

BUILDLINK_TREE+=				xkeyboard-config

.if !defined(XKEYBOARD_CONFIG_BUILDLINK3_MK)
XKEYBOARD_CONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xkeyboard-config+=	xkeyboard-config>=1.9
BUILDLINK_ABI_DEPENDS.xkeyboard-config?=	xkeyboard-config>=2.34nb1
BUILDLINK_PKGSRCDIR.xkeyboard-config?=		../../x11/xkeyboard-config
BUILDLINK_DEPMETHOD.xkeyboard-config?=		build

.endif	# XKEYBOARD_CONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-xkeyboard-config
