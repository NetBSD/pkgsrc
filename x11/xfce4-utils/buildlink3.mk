# $NetBSD: buildlink3.mk,v 1.3.2.1 2004/07/14 11:17:20 agc Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_UTILS_BUILDLINK3_MK:=	${XFCE4_UTILS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-utils
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-utils}
BUILDLINK_PACKAGES+=	xfce4-utils

.if !empty(XFCE4_UTILS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-utils+=		xfce4-utils>=4.0.6
BUILDLINK_PKGSRCDIR.xfce4-utils?=	../../x11/xfce4-utils
.endif	# XFCE4_UTILS_BUILDLINK3_MK

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
