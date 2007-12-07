# $NetBSD: buildlink3.mk,v 1.22 2007/12/07 19:43:26 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_DESKTOP_BUILDLINK3_MK:=	${XFCE4_DESKTOP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-desktop
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-desktop}
BUILDLINK_PACKAGES+=	xfce4-desktop
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-desktop

.if ${XFCE4_DESKTOP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-desktop+=	xfce4-desktop>=4.4.2
BUILDLINK_PKGSRCDIR.xfce4-desktop?=	../../x11/xfce4-desktop
.endif	# XFCE4_DESKTOP_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
