# $NetBSD: buildlink3.mk,v 1.11 2006/02/05 23:11:39 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4UTIL_BUILDLINK3_MK:=	${LIBXFCE4UTIL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxfce4util
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4util}
BUILDLINK_PACKAGES+=	libxfce4util

.if !empty(LIBXFCE4UTIL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxfce4util+=	libxfce4util>=4.2.3.2
BUILDLINK_RECOMMENDED.libxfce4util?=	libxfce4util>=4.2.3.2nb1
BUILDLINK_PKGSRCDIR.libxfce4util?=	../../x11/libxfce4util
.endif	# LIBXFCE4UTIL_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
