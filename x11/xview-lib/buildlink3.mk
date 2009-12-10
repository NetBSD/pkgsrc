# $NetBSD: buildlink3.mk,v 1.10 2009/12/10 20:35:56 abs Exp $

BUILDLINK_TREE+=	xview-lib

.if !defined(XVIEW_LIB_BUILDLINK3_MK)
XVIEW_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xview-lib+=	xview-lib>=3.2.1
BUILDLINK_ABI_DEPENDS.xview-lib?=	xview-lib>=3.2.1nb8
BUILDLINK_PKGSRCDIR.xview-lib?=	../../x11/xview-lib

.include "../../x11/libX11/buildlink3.mk"
.endif # XVIEW_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xview-lib
