# $NetBSD: buildlink3.mk,v 1.19 2025/08/30 22:46:49 wiz Exp $

BUILDLINK_TREE+=	xforms

.if !defined(XFORMS_BUILDLINK3_MK)
XFORMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xforms+=	xforms>=1.0nb2
BUILDLINK_ABI_DEPENDS.xforms+=	xforms>=1.2.5pre2nb3
BUILDLINK_PKGSRCDIR.xforms?=	../../x11/xforms

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # XFORMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xforms
