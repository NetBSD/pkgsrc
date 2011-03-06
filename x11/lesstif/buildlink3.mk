# $NetBSD: buildlink3.mk,v 1.20 2011/03/06 03:52:16 dholland Exp $

BUILDLINK_TREE+=	lesstif

.if !defined(LESSTIF_BUILDLINK3_MK)
LESSTIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lesstif+=	lesstif>=0.95.0nb1
BUILDLINK_PKGSRCDIR.lesstif?=	../../x11/lesstif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # LESSTIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-lesstif
