# $NetBSD: buildlink3.mk,v 1.44 2024/11/14 22:22:14 wiz Exp $

BUILDLINK_TREE+=	gnustep-back

.if !defined(GNUSTEP_BACK_BUILDLINK3_MK)
GNUSTEP_BACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-back+=	gnustep-back>=0.9.2
BUILDLINK_ABI_DEPENDS.gnustep-back+=	gnustep-back>=0.28.0nb15
BUILDLINK_PKGSRCDIR.gnustep-back?=	../../x11/gnustep-back

.include "../../x11/gnustep-gui/buildlink3.mk"
.endif # GNUSTEP_BACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-back
