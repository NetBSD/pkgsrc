# $NetBSD: buildlink3.mk,v 1.23 2024/04/07 07:35:19 wiz Exp $

BUILDLINK_TREE+=	gtkdatabox

.if !defined(GTKDATABOX_BUILDLINK3_MK)
GTKDATABOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkdatabox+=	gtkdatabox>=1.0.0
BUILDLINK_ABI_DEPENDS.gtkdatabox?=	gtkdatabox>=1.0.0nb9
BUILDLINK_PKGSRCDIR.gtkdatabox?=	../../x11/gtkdatabox

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GTKDATABOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkdatabox
