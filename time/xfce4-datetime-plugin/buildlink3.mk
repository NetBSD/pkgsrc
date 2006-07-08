# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK:=	${XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-datetime-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-datetime-plugin}
BUILDLINK_PACKAGES+=	xfce4-datetime-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-datetime-plugin

.if !empty(XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-datetime-plugin+=	xfce4-datetime-plugin>=0.3.1
BUILDLINK_ABI_DEPENDS.xfce4-datetime-plugin?=	xfce4-datetime-plugin>=0.3.1nb3
BUILDLINK_PKGSRCDIR.xfce4-datetime-plugin?=	../../time/xfce4-datetime-plugin
.endif	# XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
