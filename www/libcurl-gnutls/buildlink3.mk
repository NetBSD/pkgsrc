# $NetBSD: buildlink3.mk,v 1.3 2024/05/16 06:15:41 wiz Exp $

BUILDLINK_TREE+=	libcurl-gnutls

.if !defined(LIBCURL_GNUTLS_BUILDLINK3_MK)
LIBCURL_GNUTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcurl-gnutls+=	libcurl-gnutls>=7.12.3
BUILDLINK_ABI_DEPENDS.libcurl-gnutls+=	libcurl-gnutls>=8.7.1nb1
BUILDLINK_PKGSRCDIR.libcurl-gnutls?=	../../www/libcurl-gnutls

pkgbase:= libcurl-gnutls
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.libcurl-gnutls:Mlibssh2}
.  include "../../security/libssh2/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libcurl-gnutls:Mgssapi}
.  include "../../mk/krb5.buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libcurl-gnutls:Mldap}
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libcurl-gnutls:Mrtmp}
.  include "../../net/rtmpdump/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libcurl-gnutls:Midn}
.  include "../../devel/libidn2/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libcurl-gnutls:Mhttp2}
.  include "../../www/nghttp2/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif # LIBCURL_GNUTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcurl-gnutls
