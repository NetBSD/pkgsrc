# $NetBSD: buildlink3.mk,v 1.12 2017/02/06 13:54:52 wiz Exp $
#

BUILDLINK_TREE+=	deforaos-keyboard

.if !defined(DEFORAOS_KEYBOARD_BUILDLINK3_MK)
DEFORAOS_KEYBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-keyboard+=	deforaos-keyboard>=0.3.0
BUILDLINK_ABI_DEPENDS.deforaos-keyboard?=	deforaos-keyboard>=0.3.0nb2
BUILDLINK_PKGSRCDIR.deforaos-keyboard?=	../../x11/deforaos-keyboard

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_KEYBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-keyboard
