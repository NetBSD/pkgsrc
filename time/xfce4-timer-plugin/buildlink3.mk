# $NetBSD: buildlink3.mk,v 1.11 2012/02/06 12:41:47 wiz Exp $

BUILDLINK_TREE+=	xfce4-timer-plugin

.if !defined(XFCE4_TIMER_PLUGIN_BUILDLINK3_MK)
XFCE4_TIMER_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-timer-plugin+=	xfce4-timer-plugin>=0.5.1
BUILDLINK_ABI_DEPENDS.xfce4-timer-plugin?=	xfce4-timer-plugin>=0.5.1nb8
BUILDLINK_PKGSRCDIR.xfce4-timer-plugin?=	../../time/xfce4-timer-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_TIMER_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-timer-plugin
