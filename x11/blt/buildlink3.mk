# $NetBSD: buildlink3.mk,v 1.21 2023/01/29 21:15:04 ryoon Exp $

BUILDLINK_TREE+=	blt

.if !defined(BLT_BUILDLINK3_MK)
BLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blt+=	blt>=2.4z
BUILDLINK_ABI_DEPENDS.blt+=	blt>=2.4znb14
BUILDLINK_PKGSRCDIR.blt?=	../../x11/blt

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif # BLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-blt
