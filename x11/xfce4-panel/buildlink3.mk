# $NetBSD: buildlink3.mk,v 1.23 2009/03/20 19:25:54 joerg Exp $

BUILDLINK_TREE+=	xfce4-panel

.if !defined(XFCE4_PANEL_BUILDLINK3_MK)
XFCE4_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-panel+=	xfce4-panel>=4.4.3nb1
BUILDLINK_PKGSRCDIR.xfce4-panel?=	../../x11/xfce4-panel

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-panel
