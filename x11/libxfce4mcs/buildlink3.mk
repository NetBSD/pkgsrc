# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:37 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4MCS_BUILDLINK3_MK:=	${LIBXFCE4MCS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxfce4mcs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4mcs}
BUILDLINK_PACKAGES+=	libxfce4mcs

.if !empty(LIBXFCE4MCS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxfce4mcs+=		libxfce4mcs>=4.0.4nb1
BUILDLINK_PKGSRCDIR.libxfce4mcs?=	../../x11/libxfce4mcs

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# LIBXFCE4MCS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
