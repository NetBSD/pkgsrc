# $NetBSD: buildlink3.mk,v 1.5 2004/04/01 18:12:58 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXKLAVIER_BUILDLINK3_MK:=	${LIBXKLAVIER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxklavier
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxklavier}
BUILDLINK_PACKAGES+=	libxklavier

.if !empty(LIBXKLAVIER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxklavier+=		libxklavier>=1.00
BUILDLINK_PKGSRCDIR.libxklavier?=	../../x11/libxklavier
.endif	# LIBXKLAVIER_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
