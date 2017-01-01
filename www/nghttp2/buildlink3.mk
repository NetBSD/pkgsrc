# $NetBSD: buildlink3.mk,v 1.4 2017/01/01 16:06:01 adam Exp $

BUILDLINK_TREE+=	nghttp2

.if !defined(NGHTTP2_BUILDLINK3_MK)
NGHTTP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nghttp2+=	nghttp2>=1.0.0
BUILDLINK_ABI_DEPENDS.nghttp2+=	nghttp2>=1.17.0nb1
BUILDLINK_PKGSRCDIR.nghttp2?=	../../www/nghttp2

pkgbase := nghttp2
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.nghttp2:Mnghttp2-asio)
.  include "../../devel/boost-libs/buildlink3.mk"
.  include "../../security/openssl/buildlink3.mk"
.endif
.endif # NGHTTP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-nghttp2
