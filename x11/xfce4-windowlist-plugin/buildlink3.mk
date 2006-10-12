# $NetBSD: buildlink3.mk,v 1.11 2006/10/12 09:24:21 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_WINDOWLIST_PLUGIN_BUILDLINK3_MK:=	${XFCE4_WINDOWLIST_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-windowlist-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-windowlist-plugin}
BUILDLINK_PACKAGES+=	xfce4-windowlist-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-windowlist-plugin

.if ${XFCE4_WINDOWLIST_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-windowlist-plugin+=	xfce4-windowlist-plugin>=0.1.0nb4
BUILDLINK_PKGSRCDIR.xfce4-windowlist-plugin?=	../../x11/xfce4-windowlist-plugin
.endif	# XFCE4_WINDOWLIST_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
