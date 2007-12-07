# $NetBSD: buildlink3.mk,v 1.20 2007/12/07 19:43:30 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MCS_PLUGINS_BUILDLINK3_MK:=	${XFCE4_MCS_PLUGINS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-mcs-plugins
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mcs-plugins}
BUILDLINK_PACKAGES+=	xfce4-mcs-plugins
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-mcs-plugins

.if ${XFCE4_MCS_PLUGINS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-mcs-plugins+=	xfce4-mcs-plugins>=4.4.2
BUILDLINK_PKGSRCDIR.xfce4-mcs-plugins?=	../../x11/xfce4-mcs-plugins
.endif	# XFCE4_MCS_PLUGINS_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-manager/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
