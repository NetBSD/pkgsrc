# $NetBSD: buildlink3.mk,v 1.23 2012/02/06 12:41:47 wiz Exp $

BUILDLINK_TREE+=	xfce4-datetime-plugin

.if !defined(XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK)
XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-datetime-plugin+=	xfce4-datetime-plugin>=0.4.1
BUILDLINK_ABI_DEPENDS.xfce4-datetime-plugin?=	xfce4-datetime-plugin>=0.6.1nb7
BUILDLINK_PKGSRCDIR.xfce4-datetime-plugin?=	../../time/xfce4-datetime-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-datetime-plugin
