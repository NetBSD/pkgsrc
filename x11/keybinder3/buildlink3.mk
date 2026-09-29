# $NetBSD: buildlink3.mk,v 1.28 2026/09/29 06:08:19 wiz Exp $

BUILDLINK_TREE+=	keybinder3

.if !defined(KEYBINDER3_BUILDLINK3_MK)
KEYBINDER3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.keybinder3+=	keybinder3>=0.3.0
BUILDLINK_ABI_DEPENDS.keybinder3+=	keybinder3>=0.3.2nb27
BUILDLINK_PKGSRCDIR.keybinder3?=	../../x11/keybinder3

.include "../../x11/gtk3/buildlink3.mk"
.endif	# KEYBINDER3_BUILDLINK3_MK

BUILDLINK_TREE+=	-keybinder3
