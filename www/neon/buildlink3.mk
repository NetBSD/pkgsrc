# $NetBSD: buildlink3.mk,v 1.5 2006/01/24 07:32:49 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NEON_BUILDLINK3_MK:=	${NEON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	neon
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nneon}
BUILDLINK_PACKAGES+=	neon

.if !empty(NEON_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.neon+=	neon>=0.24.4
BUILDLINK_RECOMMENDED.neon+=	neon>=0.25.5nb1
BUILDLINK_PKGSRCDIR.neon?=	../../www/neon
.endif	# NEON_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
