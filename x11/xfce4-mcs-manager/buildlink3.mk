# $NetBSD: buildlink3.mk,v 1.20 2007/12/07 19:43:29 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MCS_MANAGER_BUILDLINK3_MK:=	${XFCE4_MCS_MANAGER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-mcs-manager
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mcs-manager}
BUILDLINK_PACKAGES+=	xfce4-mcs-manager
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-mcs-manager

.if ${XFCE4_MCS_MANAGER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-mcs-manager+=	xfce4-mcs-manager>=4.4.2
BUILDLINK_PKGSRCDIR.xfce4-mcs-manager?=	../../x11/xfce4-mcs-manager
.endif	# XFCE4_MCS_MANAGER_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4mcs/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
