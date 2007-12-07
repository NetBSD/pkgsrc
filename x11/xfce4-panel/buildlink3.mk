# $NetBSD: buildlink3.mk,v 1.21 2007/12/07 19:43:30 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_PANEL_BUILDLINK3_MK:=	${XFCE4_PANEL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-panel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-panel}
BUILDLINK_PACKAGES+=	xfce4-panel
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-panel

.if ${XFCE4_PANEL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-panel+=	xfce4-panel>=4.4.2
BUILDLINK_PKGSRCDIR.xfce4-panel?=	../../x11/xfce4-panel
.endif	# XFCE4_PANEL_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
