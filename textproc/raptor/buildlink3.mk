# $NetBSD: buildlink3.mk,v 1.10 2008/01/18 05:09:45 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RAPTOR_BUILDLINK3_MK:=	${RAPTOR_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	raptor
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nraptor}
BUILDLINK_PACKAGES+=	raptor
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}raptor

.if ${RAPTOR_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.raptor?=	raptor>=1.0.0
BUILDLINK_ABI_DEPENDS.raptor+=	raptor>=1.4.15nb1
BUILDLINK_PKGSRCDIR.raptor?=	../../textproc/raptor
.endif	# RAPTOR_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
