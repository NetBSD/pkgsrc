# $NetBSD: buildlink3.mk,v 1.2 2004/11/28 09:56:29 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_TASKBAR_PLUGIN_BUILDLINK3_MK:=	${XFCE4_TASKBAR_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-taskbar-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-taskbar-plugin}
BUILDLINK_PACKAGES+=	xfce4-taskbar-plugin

.if !empty(XFCE4_TASKBAR_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-taskbar-plugin+=	xfce4-taskbar-plugin>=0.2.2
BUILDLINK_PKGSRCDIR.xfce4-taskbar-plugin?=	../../x11/xfce4-taskbar-plugin
.endif	# XFCE4_TASKBAR_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
