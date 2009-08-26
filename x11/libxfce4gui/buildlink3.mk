# $NetBSD: buildlink3.mk,v 1.26 2009/08/26 19:56:58 sno Exp $

BUILDLINK_TREE+=	libxfce4gui

.if !defined(LIBXFCE4GUI_BUILDLINK3_MK)
LIBXFCE4GUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4gui+=	libxfce4gui>=4.4.3nb1
BUILDLINK_ABI_DEPENDS.libxfce4gui?=	libxfce4gui>=4.4.3nb2
BUILDLINK_PKGSRCDIR.libxfce4gui?=	../../x11/libxfce4gui

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBXFCE4GUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4gui
