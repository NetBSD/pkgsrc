# $NetBSD: buildlink3.mk,v 1.14 2007/01/15 19:26:33 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXKLAVIER_BUILDLINK3_MK:=	${LIBXKLAVIER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxklavier
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxklavier}
BUILDLINK_PACKAGES+=	libxklavier
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxklavier

.if !empty(LIBXKLAVIER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=3.0
BUILDLINK_PKGSRCDIR.libxklavier?=	../../x11/libxklavier
.endif	# LIBXKLAVIER_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
