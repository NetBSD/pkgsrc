# $NetBSD: options.mk,v 1.27 2026/01/19 19:25:40 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.curl
PKG_SUPPORTED_OPTIONS=		inet6 openssl libssh2 gssapi ldap rtmp idn http2
PKG_SUPPORTED_OPTIONS+=		brotli zstd
PKG_SUGGESTED_OPTIONS=		http2 inet6 idn
.if ${OPSYS} != "QNX"
PKG_SUGGESTED_OPTIONS+=		openssl
.endif
PKG_OPTIONS_LEGACY_OPTS=	libidn:idn

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
BUILDLINK_API_DEPENDS.openssl+=	openssl>=3.0
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if !empty(PKG_OPTIONS:Mlibssh2)
CONFIGURE_ARGS+=	--with-libssh2=${BUILDLINK_PREFIX.libssh2}
.  include "../../security/libssh2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libssh2
.endif

.if !empty(PKG_OPTIONS:Mgssapi)
# does not support heimdal after 8.17.0
KRB5_ACCEPTED=		mit-krb5
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gssapi-includes=${KRB5BASE}/include/gssapi
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ldap
CONFIGURE_ARGS+=	--enable-ldaps
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !empty(PKG_OPTIONS:Mrtmp)
.include "../../net/rtmpdump/buildlink3.mk"
CONFIGURE_ARGS+=	--with-librtmp
.else
CONFIGURE_ARGS+=	--without-librtmp
.endif

.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn2
.else
CONFIGURE_ARGS+=	--without-libidn2
.endif

.if !empty(PKG_OPTIONS:Mhttp2)
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-nghttp2=${BUILDLINK_PREFIX.nghttp2}
TEST_DEPENDS+=		nghttp2-tools-[0-9]*:../../www/nghttp2-tools
.include "../../www/nghttp2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-nghttp2
.endif

.if !empty(PKG_OPTIONS:Mbrotli)
.include "../../archivers/brotli/buildlink3.mk"
CONFIGURE_ARGS+=	--with-brotli
.else
CONFIGURE_ARGS+=	--without-brotli
.endif

.if !empty(PKG_OPTIONS:Mzstd)
.include "../../archivers/zstd/buildlink3.mk"
CONFIGURE_ARGS+=	--with-zstd
.else
CONFIGURE_ARGS+=	--without-zstd
.endif
