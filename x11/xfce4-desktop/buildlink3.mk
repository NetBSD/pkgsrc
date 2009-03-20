# $NetBSD: buildlink3.mk,v 1.24 2009/03/20 19:25:53 joerg Exp $

BUILDLINK_TREE+=	xfce4-desktop

.if !defined(XFCE4_DESKTOP_BUILDLINK3_MK)
XFCE4_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-desktop+=	xfce4-desktop>=4.4.3nb1
BUILDLINK_PKGSRCDIR.xfce4-desktop?=	../../x11/xfce4-desktop

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-desktop
