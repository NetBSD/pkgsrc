# $NetBSD: buildlink3.mk,v 1.17 2006/10/12 09:24:20 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4MCS_BUILDLINK3_MK:=	${LIBXFCE4MCS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libxfce4mcs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4mcs}
BUILDLINK_PACKAGES+=	libxfce4mcs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxfce4mcs

.if ${LIBXFCE4MCS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libxfce4mcs+=	libxfce4mcs>=4.2.3nb2
BUILDLINK_PKGSRCDIR.libxfce4mcs?=	../../x11/libxfce4mcs
.endif	# LIBXFCE4MCS_BUILDLINK3_MK

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
