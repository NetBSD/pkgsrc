# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:38 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_UTILS_BUILDLINK3_MK:=	${XFCE4_UTILS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-utils
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-utils}
BUILDLINK_PACKAGES+=	xfce4-utils

.if !empty(XFCE4_UTILS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-utils+=		xfce4-utils>=4.0.4nb1
BUILDLINK_PKGSRCDIR.xfce4-utils?=	../../x11/xfce4-utils

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_UTILS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
