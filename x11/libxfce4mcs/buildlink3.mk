# $NetBSD: buildlink3.mk,v 1.7 2005/03/18 07:59:09 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4MCS_BUILDLINK3_MK:=	${LIBXFCE4MCS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxfce4mcs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4mcs}
BUILDLINK_PACKAGES+=	libxfce4mcs

.if !empty(LIBXFCE4MCS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxfce4mcs+=		libxfce4mcs>=4.2.1
BUILDLINK_PKGSRCDIR.libxfce4mcs?=	../../x11/libxfce4mcs
.endif	# LIBXFCE4MCS_BUILDLINK3_MK

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
