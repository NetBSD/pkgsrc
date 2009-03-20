# $NetBSD: buildlink3.mk,v 1.25 2009/03/20 19:25:35 joerg Exp $

BUILDLINK_TREE+=	xfce4-wm

.if !defined(XFCE4_WM_BUILDLINK3_MK)
XFCE4_WM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-wm+=	xfce4-wm>=4.4.3nb1
BUILDLINK_PKGSRCDIR.xfce4-wm?=	../../wm/xfce4-wm

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_WM_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-wm
