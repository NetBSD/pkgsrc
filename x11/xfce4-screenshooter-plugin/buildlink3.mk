# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/27 10:48:06 martti Exp $

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
XFCE4_SCREENSHOOTER_PLUGIN_BUILDLINK3_MK:=	${XFCE4_SCREENSHOOTER_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-screenshooter-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-screenshooter-plugin}
BUILDLINK_PACKAGES+=	xfce4-screenshooter-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-screenshooter-plugin

.if ${XFCE4_SCREENSHOOTER_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-screenshooter-plugin+=	xfce4-screenshooter-plugin>=1.0.0
BUILDLINK_PKGSRCDIR.xfce4-screenshooter-plugin?=	../../x11/xfce4-screenshooter-plugin
.endif	# XFCE4_SCREENSHOOTER_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH:S/+$//}
