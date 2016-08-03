# $NetBSD: buildlink3.mk,v 1.2 2016/08/03 10:22:23 adam Exp $
#

BUILDLINK_TREE+=	mate-panel

.if !defined(MATE_PANEL_BUILDLINK3_MK)
MATE_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-panel+=	mate-panel>=1.8.1
BUILDLINK_ABI_DEPENDS.mate-panel?=	mate-panel>=1.14.1nb2
BUILDLINK_PKGSRCDIR.mate-panel?=	../../x11/mate-panel

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.endif	# MATE_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-panel
