# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:25:37 joerg Exp $

BUILDLINK_TREE+=	neon

.if !defined(NEON_BUILDLINK3_MK)
NEON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.neon+=	neon>=0.24.4
BUILDLINK_ABI_DEPENDS.neon+=	neon>=0.26.3nb2
BUILDLINK_PKGSRCDIR.neon?=	../../www/neon

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # NEON_BUILDLINK3_MK

BUILDLINK_TREE+=	-neon
