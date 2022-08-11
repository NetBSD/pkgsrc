# $NetBSD: buildlink3.mk,v 1.8 2022/08/11 05:09:28 gutteridge Exp $

BUILDLINK_TREE+=	keybinder3

.if !defined(KEYBINDER3_BUILDLINK3_MK)
KEYBINDER3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.keybinder3+=	keybinder3>=0.3.0
BUILDLINK_ABI_DEPENDS.keybinder3+=	keybinder3>=0.3.2nb8
BUILDLINK_PKGSRCDIR.keybinder3?=	../../x11/keybinder3

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# KEYBINDER3_BUILDLINK3_MK

BUILDLINK_TREE+=	-keybinder3
