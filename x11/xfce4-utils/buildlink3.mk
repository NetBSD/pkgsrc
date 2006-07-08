# $NetBSD: buildlink3.mk,v 1.19 2006/07/08 23:11:17 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_UTILS_BUILDLINK3_MK:=	${XFCE4_UTILS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-utils
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-utils}
BUILDLINK_PACKAGES+=	xfce4-utils
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-utils

.if !empty(XFCE4_UTILS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-utils+=	xfce4-utils>=4.2.3
BUILDLINK_ABI_DEPENDS.xfce4-utils?=	xfce4-utils>=4.2.3nb5
BUILDLINK_PKGSRCDIR.xfce4-utils?=	../../x11/xfce4-utils
.endif	# XFCE4_UTILS_BUILDLINK3_MK

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
