# $NetBSD: buildlink3.mk,v 1.15 2021/11/20 20:56:05 hauke Exp $

BUILDLINK_TREE+=	gtkdatabox

.if !defined(GTKDATABOX_BUILDLINK3_MK)
GTKDATABOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkdatabox+=	gtkdatabox>=1.0.0
BUILDLINK_ABI_DEPENDS.gtkdatabox?=	gtkdatabox>=1.0.0
BUILDLINK_PKGSRCDIR.gtkdatabox?=	../../x11/gtkdatabox

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GTKDATABOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkdatabox
