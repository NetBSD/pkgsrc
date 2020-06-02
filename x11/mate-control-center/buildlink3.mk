# $NetBSD: buildlink3.mk,v 1.13 2020/06/02 08:23:06 adam Exp $
#

BUILDLINK_TREE+=	mate-control-center

.if !defined(MATE_CONTROL_CENTER_BUILDLINK3_MK)
MATE_CONTROL_CENTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-control-center+=	mate-control-center>=1.8.3
BUILDLINK_ABI_DEPENDS.mate-control-center+=	mate-control-center>=1.24.0nb1
BUILDLINK_PKGSRCDIR.mate-control-center?=	../../x11/mate-control-center

.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# MATE_CONTROL_CENTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-control-center
