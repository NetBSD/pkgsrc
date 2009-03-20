# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:25:34 joerg Exp $

BUILDLINK_TREE+=	xfce4-datetime-plugin

.if !defined(XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK)
XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-datetime-plugin+=	xfce4-datetime-plugin>=0.4.1
BUILDLINK_PKGSRCDIR.xfce4-datetime-plugin?=	../../time/xfce4-datetime-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-datetime-plugin
