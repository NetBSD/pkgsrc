# $NetBSD: buildlink3.mk,v 1.15 2007/04/12 09:55:21 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK:=	${XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-clipman-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-clipman-plugin}
BUILDLINK_PACKAGES+=	xfce4-clipman-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-clipman-plugin

.if ${XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-clipman-plugin+=	xfce4-clipman-plugin>=0.8.0
BUILDLINK_PKGSRCDIR.xfce4-clipman-plugin?=	../../x11/xfce4-clipman-plugin
.endif	# XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
