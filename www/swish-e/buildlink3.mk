# $NetBSD: buildlink3.mk,v 1.1 2007/08/29 14:17:06 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWISH_E_BUILDLINK3_MK:=	${SWISH_E_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	swish-e
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswish-e}
BUILDLINK_PACKAGES+=	swish-e
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}swish-e

.if ${SWISH_E_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.swish-e+=	swish-e>=2.4.5nb1
BUILDLINK_PKGSRCDIR.swish-e?=	../../www/swish-e
.endif	# SWISH_E_BUILDLINK3_MK

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
