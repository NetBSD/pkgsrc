# $NetBSD: buildlink3.mk,v 1.29 2024/04/06 08:06:56 wiz Exp $
#

BUILDLINK_TREE+=	deforaos-keyboard

.if !defined(DEFORAOS_KEYBOARD_BUILDLINK3_MK)
DEFORAOS_KEYBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-keyboard+=	deforaos-keyboard>=0.3.0
BUILDLINK_ABI_DEPENDS.deforaos-keyboard?=	deforaos-keyboard>=0.4.0nb11
BUILDLINK_PKGSRCDIR.deforaos-keyboard?=		../../x11/deforaos-keyboard

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_KEYBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-keyboard
