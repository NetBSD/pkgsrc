# $NetBSD: buildlink3.mk,v 1.4 2004/10/08 06:23:36 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK:=	${XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-clipman-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-clipman-plugin}
BUILDLINK_PACKAGES+=	xfce4-clipman-plugin

.if !empty(XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-clipman-plugin+=	xfce4-clipman-plugin>=0.4.1
BUILDLINK_RECOMMENDED.xfce4-clipman-plugin+=	xfce4-clipman-plugin>=0.4.1
BUILDLINK_PKGSRCDIR.xfce4-clipman-plugin?=	../../x11/xfce4-clipman-plugin
.endif	# XFCE4_CLIPMAN_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
