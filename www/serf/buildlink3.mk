# $NetBSD: buildlink3.mk,v 1.6 2008/02/13 19:40:13 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SERF_BUILDLINK3_MK:=	${SERF_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	serf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nserf}
BUILDLINK_PACKAGES+=	serf
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}serf

.if ${SERF_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.serf+=	serf>=0.1.0
BUILDLINK_ABI_DEPENDS.serf?=	serf>=0.1.2nb2
BUILDLINK_PKGSRCDIR.serf?=	../../www/serf
.endif	# SERF_BUILDLINK3_MK

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
