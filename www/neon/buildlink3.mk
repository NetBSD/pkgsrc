# $NetBSD: buildlink3.mk,v 1.31 2024/05/16 06:15:42 wiz Exp $

BUILDLINK_TREE+=	neon

.if !defined(NEON_BUILDLINK3_MK)
NEON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.neon+=	neon>=0.24.4
BUILDLINK_ABI_DEPENDS.neon+=	neon>=0.33.0nb1
BUILDLINK_PKGSRCDIR.neon?=	../../www/neon

pkgbase := neon
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.neon:Mgnutls}
.include "../../security/gnutls/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.neon:Mopenssl}
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # NEON_BUILDLINK3_MK

BUILDLINK_TREE+=	-neon
