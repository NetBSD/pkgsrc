# $NetBSD: buildlink3.mk,v 1.24 2007/12/07 19:43:31 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_UTILS_BUILDLINK3_MK:=	${XFCE4_UTILS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-utils
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-utils}
BUILDLINK_PACKAGES+=	xfce4-utils
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-utils

.if ${XFCE4_UTILS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-utils+=	xfce4-utils>=4.4.2
BUILDLINK_PKGSRCDIR.xfce4-utils?=	../../x11/xfce4-utils
.endif	# XFCE4_UTILS_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
