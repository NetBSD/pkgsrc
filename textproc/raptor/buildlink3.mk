# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RAPTOR_BUILDLINK3_MK:=	${RAPTOR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	raptor
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nraptor}
BUILDLINK_PACKAGES+=	raptor
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}raptor

.if !empty(RAPTOR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.raptor?=		raptor>=1.0.0
BUILDLINK_ABI_DEPENDS.raptor+=		raptor>=1.0.0nb6
.endif	# RAPTOR_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
