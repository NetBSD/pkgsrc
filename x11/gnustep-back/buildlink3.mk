# $NetBSD: buildlink3.mk,v 1.34 2020/04/12 08:28:10 adam Exp $

BUILDLINK_TREE+=	gnustep-back

.if !defined(GNUSTEP_BACK_BUILDLINK3_MK)
GNUSTEP_BACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-back+=	gnustep-back>=0.9.2
BUILDLINK_ABI_DEPENDS.gnustep-back+=	gnustep-back>=0.22.0nb22
BUILDLINK_PKGSRCDIR.gnustep-back?=	../../x11/gnustep-back

.include "../../x11/gnustep-gui/buildlink3.mk"
.endif # GNUSTEP_BACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-back
