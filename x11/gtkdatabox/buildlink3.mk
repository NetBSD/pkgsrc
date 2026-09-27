# $NetBSD: buildlink3.mk,v 1.33 2026/09/27 11:39:17 tnn Exp $

BUILDLINK_TREE+=	gtkdatabox

.if !defined(GTKDATABOX_BUILDLINK3_MK)
GTKDATABOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkdatabox+=	gtkdatabox>=1.0.0
BUILDLINK_ABI_DEPENDS.gtkdatabox?=	gtkdatabox>=1.0.0nb19
BUILDLINK_PKGSRCDIR.gtkdatabox?=	../../x11/gtkdatabox

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GTKDATABOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkdatabox
