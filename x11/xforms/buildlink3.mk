# $NetBSD: buildlink3.mk,v 1.17 2023/10/21 17:11:58 gdt Exp $

BUILDLINK_TREE+=	xforms

.if !defined(XFORMS_BUILDLINK3_MK)
XFORMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xforms+=	xforms>=1.0nb2
BUILDLINK_ABI_DEPENDS.xforms+=	xforms>=1.2.5pre2nb1
BUILDLINK_PKGSRCDIR.xforms?=	../../x11/xforms

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # XFORMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xforms
