# $NetBSD: buildlink3.mk,v 1.16 2010/01/17 12:02:49 wiz Exp $

BUILDLINK_TREE+=	neon

.if !defined(NEON_BUILDLINK3_MK)
NEON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.neon+=	neon>=0.24.4
BUILDLINK_ABI_DEPENDS.neon+=	neon>=0.29.0nb1
BUILDLINK_PKGSRCDIR.neon?=	../../www/neon

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # NEON_BUILDLINK3_MK

BUILDLINK_TREE+=	-neon
