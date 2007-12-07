# $NetBSD: buildlink3.mk,v 1.23 2007/12/07 19:43:24 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_WM_BUILDLINK3_MK:=	${XFCE4_WM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-wm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-wm}
BUILDLINK_PACKAGES+=	xfce4-wm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-wm

.if ${XFCE4_WM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-wm+=	xfce4-wm>=4.4.2
BUILDLINK_PKGSRCDIR.xfce4-wm?=	../../wm/xfce4-wm
.endif	# XFCE4_WM_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
