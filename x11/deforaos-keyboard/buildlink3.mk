# $NetBSD: buildlink3.mk,v 1.18 2018/11/14 22:22:38 kleink Exp $
#

BUILDLINK_TREE+=	deforaos-keyboard

.if !defined(DEFORAOS_KEYBOARD_BUILDLINK3_MK)
DEFORAOS_KEYBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-keyboard+=	deforaos-keyboard>=0.3.0
BUILDLINK_ABI_DEPENDS.deforaos-keyboard?=	deforaos-keyboard>=0.3.1nb4
BUILDLINK_PKGSRCDIR.deforaos-keyboard?=		../../x11/deforaos-keyboard

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_KEYBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-keyboard
