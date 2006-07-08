# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:15 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXKLAVIER_BUILDLINK3_MK:=	${LIBXKLAVIER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxklavier
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxklavier}
BUILDLINK_PACKAGES+=	libxklavier
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxklavier

.if !empty(LIBXKLAVIER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libxklavier+=		libxklavier>=2.0
BUILDLINK_ABI_DEPENDS.libxklavier?=	libxklavier>=2.0nb1
BUILDLINK_PKGSRCDIR.libxklavier?=	../../x11/libxklavier
.endif	# LIBXKLAVIER_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
