# $NetBSD: buildlink3.mk,v 1.15 2020/05/06 14:04:15 adam Exp $

BUILDLINK_TREE+=	nghttp2

.if !defined(NGHTTP2_BUILDLINK3_MK)
NGHTTP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nghttp2+=	nghttp2>=1.0.0
BUILDLINK_ABI_DEPENDS.nghttp2+=	nghttp2>=1.40.0nb4
BUILDLINK_PKGSRCDIR.nghttp2?=	../../www/nghttp2

pkgbase := nghttp2
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.nghttp2:Mnghttp2-asio}
.  include "../../devel/boost-libs/buildlink3.mk"
.  include "../../security/openssl/buildlink3.mk"
.endif
.endif # NGHTTP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-nghttp2
