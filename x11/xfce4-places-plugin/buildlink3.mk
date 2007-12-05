# $NetBSD: buildlink3.mk,v 1.2 2007/12/05 07:51:18 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_PLACES_PLUGIN_BUILDLINK3_MK:=	${XFCE4_PLACES_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-places-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-places-plugin}
BUILDLINK_PACKAGES+=	xfce4-places-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-places-plugin

.if ${XFCE4_PLACES_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-places-plugin+=	xfce4-places-plugin>=1.0.0
BUILDLINK_PKGSRCDIR.xfce4-places-plugin?=	../../x11/xfce4-places-plugin
.endif	# XFCE4_PLACES_PLUGIN_BUILDLINK3_MK

.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
