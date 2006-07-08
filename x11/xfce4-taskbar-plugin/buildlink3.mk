# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:17 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_TASKBAR_PLUGIN_BUILDLINK3_MK:=	${XFCE4_TASKBAR_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-taskbar-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-taskbar-plugin}
BUILDLINK_PACKAGES+=	xfce4-taskbar-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-taskbar-plugin

.if !empty(XFCE4_TASKBAR_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-taskbar-plugin+=	xfce4-taskbar-plugin>=0.2.2
BUILDLINK_ABI_DEPENDS.xfce4-taskbar-plugin?=	xfce4-taskbar-plugin>=0.2.2nb3
BUILDLINK_PKGSRCDIR.xfce4-taskbar-plugin?=	../../x11/xfce4-taskbar-plugin
.endif	# XFCE4_TASKBAR_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
