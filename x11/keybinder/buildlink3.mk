# $NetBSD: buildlink3.mk,v 1.29 2026/05/15 20:08:43 wiz Exp $

BUILDLINK_TREE+=	keybinder

.if !defined(KEYBINDER_BUILDLINK3_MK)
KEYBINDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.keybinder+=	keybinder>=0.3.0
BUILDLINK_ABI_DEPENDS.keybinder?=	keybinder>=0.3.0nb27
BUILDLINK_PKGSRCDIR.keybinder?=		../../x11/keybinder

.include "../../x11/gtk2/buildlink3.mk"
.endif	# KEYBINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-keybinder
