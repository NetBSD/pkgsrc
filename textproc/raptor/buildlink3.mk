# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:18:21 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RAPTOR_BUILDLINK3_MK:=	${RAPTOR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	raptor
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nraptor}
BUILDLINK_PACKAGES+=	raptor

.if !empty(RAPTOR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.raptor?=		raptor>=1.0.0
BUILDLINK_RECOMMENDED.raptor+=		raptor>=1.0.0nb4
.endif	# RAPTOR_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
