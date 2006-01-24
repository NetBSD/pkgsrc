# $NetBSD: buildlink3.mk,v 1.4 2006/01/24 07:32:39 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK:=	${XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-datetime-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-datetime-plugin}
BUILDLINK_PACKAGES+=	xfce4-datetime-plugin

.if !empty(XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-datetime-plugin+=	xfce4-datetime-plugin>=0.3.1
BUILDLINK_RECOMMENDED.xfce4-datetime-plugin?=	xfce4-datetime-plugin>=0.3.1nb1
BUILDLINK_PKGSRCDIR.xfce4-datetime-plugin?=	../../time/xfce4-datetime-plugin
.endif	# XFCE4_DATETIME_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
