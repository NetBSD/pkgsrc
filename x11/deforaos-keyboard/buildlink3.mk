# $NetBSD: buildlink3.mk,v 1.5 2013/06/06 12:53:56 wiz Exp $
#

BUILDLINK_TREE+=	deforaos-keyboard

.if !defined(DEFORAOS_KEYBOARD_BUILDLINK3_MK)
DEFORAOS_KEYBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-keyboard+=	deforaos-keyboard>=0.0.2
BUILDLINK_ABI_DEPENDS.deforaos-keyboard?=	deforaos-keyboard>=0.2.1nb5
BUILDLINK_PKGSRCDIR.deforaos-keyboard?=	../../x11/deforaos-keyboard

.include "../../x11/gtk2/buildlink3.mk"
.endif	# DEFORAOS_KEYBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-keyboard
