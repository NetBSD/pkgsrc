# $NetBSD: buildlink3.mk,v 1.17 2009/03/20 19:25:41 joerg Exp $

BUILDLINK_TREE+=	gnustep-back

.if !defined(GNUSTEP_BACK_BUILDLINK3_MK)
GNUSTEP_BACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-back+=	gnustep-back>=0.9.2
BUILDLINK_ABI_DEPENDS.gnustep-back+=	gnustep-back>=0.12.0nb1
BUILDLINK_PKGSRCDIR.gnustep-back?=	../../x11/gnustep-back

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.endif # GNUSTEP_BACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-back
