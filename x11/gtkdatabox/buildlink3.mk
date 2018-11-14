# $NetBSD: buildlink3.mk,v 1.10 2018/11/14 22:22:43 kleink Exp $

BUILDLINK_TREE+=	gtkdatabox

.if !defined(GTKDATABOX_BUILDLINK3_MK)
GTKDATABOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkdatabox+=	gtkdatabox>=0.9.2.0
BUILDLINK_ABI_DEPENDS.gtkdatabox?=	gtkdatabox>=0.9.2.0nb9
BUILDLINK_PKGSRCDIR.gtkdatabox?=	../../x11/gtkdatabox

.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# GTKDATABOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkdatabox
