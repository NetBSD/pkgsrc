# $NetBSD: buildlink3.mk,v 1.16 2009/03/20 19:25:53 joerg Exp $

BUILDLINK_TREE+=	xfce4-clipman-plugin

.if !defined(XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK)
XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-clipman-plugin+=	xfce4-clipman-plugin>=0.8.0
BUILDLINK_PKGSRCDIR.xfce4-clipman-plugin?=	../../x11/xfce4-clipman-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-clipman-plugin
