# $NetBSD: buildlink3.mk,v 1.4 2023/07/09 09:50:47 nia Exp $

BUILDLINK_TREE+=	c-icap

.if !defined(C_ICAP_BUILDLINK3_MK)
C_ICAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.c-icap+=	c-icap>=0.3.5
BUILDLINK_ABI_DEPENDS.c-icap?=	c-icap>=0.5.5nb4
BUILDLINK_PKGSRCDIR.c-icap?=	../../www/c-icap

pkgbase:= c-icap

.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.c-icap:Mbrotli}
.  include "../../archivers/brotli/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.c-icap:Mbzip2}
.  include "../../archivers/bzip2/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.c-icap:Mopenssl}
.  include "../../security/openssl/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.c-icap:Mzlib}
.  include "../../devel/zlib/buildlink3.mk"
.endif
.endif	# C_ICAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-c-icap
