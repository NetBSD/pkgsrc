# $NetBSD: buildlink3.mk,v 1.24 2009/09/16 01:31:13 reed Exp $

BUILDLINK_TREE+=	xfce4-mcs-plugins

.if !defined(XFCE4_MCS_PLUGINS_BUILDLINK3_MK)
XFCE4_MCS_PLUGINS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mcs-plugins+=	xfce4-mcs-plugins>=4.4.3nb1
BUILDLINK_ABI_DEPENDS.xfce4-mcs-plugins?=	xfce4-mcs-plugins>=4.4.3nb2
BUILDLINK_PKGSRCDIR.xfce4-mcs-plugins?=	../../x11/xfce4-mcs-plugins

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-manager/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_MCS_PLUGINS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mcs-plugins
