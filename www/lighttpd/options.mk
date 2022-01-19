# $NetBSD: options.mk,v 1.27 2022/01/19 21:41:48 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lighttpd
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls mbedtls nss openssl wolfssl
PKG_SUPPORTED_OPTIONS+=		brotli bzip2 fam inet6 ldap libdbi lua
PKG_SUPPORTED_OPTIONS+=		mysql geoip gssapi webdav
PKG_SUGGESTED_OPTIONS=		inet6 openssl

.include "../../mk/bsd.options.mk"

###
### Allow using brotli as a compression method in the "deflate" module.
###
.if !empty(PKG_OPTIONS:Mbrotli)
.  include "../../archivers/brotli/buildlink3.mk"
CONFIGURE_ARGS+=	--with-brotli
.else
CONFIGURE_ARGS+=	--without-brotli
.endif

###
### Allow using bzip2 as a compression method in the "deflate" module.
###
.if !empty(PKG_OPTIONS:Mbzip2)
.  include "../../archivers/bzip2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-bzip2
.else
CONFIGURE_ARGS+=	--without-bzip2
.endif

###
### Use FAM to optimize number of stat() syscalls used.
###
.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-fam
.else
CONFIGURE_ARGS+=	--without-fam
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### Allow using LDAP for "basic" authentication.
###
PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

###
### libdbi
###
PLIST_VARS+=		libdbi
.if !empty(PKG_OPTIONS:Mlibdbi)
.  include "../../databases/libdbi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dbi
PLIST.libdbi=		yes
.else
CONFIGURE_ARGS+=	--without-dbi
.endif

###
### Support enabling the Cache Meta Language module with the Lua engine.
###
PLIST_VARS+=		lua
.if !empty(PKG_OPTIONS:Mlua)
.  include "../../lang/lua/buildlink3.mk"
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-lua
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--without-lua
.endif

###
### Allow using MySQL for virtual host configuration.
###
PLIST_VARS+=		mysql
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
MYSQL_CONFIG?=		${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
CONFIGURE_ARGS+=	--with-mysql=${MYSQL_CONFIG:Q}
PLIST.mysql=		yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

###
### HTTPS support via GnuTLS
###
PLIST_VARS+=		gnutls
.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnutls=${BUILDLINK_PREFIX.gnutls}
PLIST.gnutls=		yes
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

###
### HTTPS support via mbedTLS
###
PLIST_VARS+=		mbedtls
.if !empty(PKG_OPTIONS:Mmbedtls)
.  include "../../security/mbedtls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mbedtls=${BUILDLINK_PREFIX.mbedtls}
PLIST.mbedtls=		yes
.else
CONFIGURE_ARGS+=	--without-mbedtls
.endif

###
### HTTPS support via nss
###
PLIST_VARS+=		nss
.if !empty(PKG_OPTIONS:Mnss)
.  include "../../devel/nss/buildlink3.mk"
CONFIGURE_ARGS+=	--with-nss=${BUILDLINK_PREFIX.nss}
PLIST.nss=		yes
.else
CONFIGURE_ARGS+=	--without-nss
.endif

###
### HTTPS support via OpenSSL
###
PLIST_VARS+=		openssl
.if !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
PLIST.openssl=		yes
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

###
### HTTPS support via WolfSSL
###
PLIST_VARS+=		wolfssl
.if !empty(PKG_OPTIONS:Mwolfssl)
.  include "../../security/wolfssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wolfssl=${BUILDLINK_PREFIX.wolfssl}
PLIST.wolfssl=		yes
.else
CONFIGURE_ARGS+=	--without-wolfssl
.endif

###
### GeoIP support
###
PLIST_VARS+=		geoip
.if !empty(PKG_OPTIONS:Mgeoip)
.  include "../../geography/libmaxminddb/buildlink3.mk"
CONFIGURE_ARGS+=	--with-maxminddb
PLIST.geoip=		yes
.else
CONFIGURE_ARGS+=	--without-maxminddb
.endif

###
### gssapi
###
PLIST_VARS+=		gssapi
.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../security/mit-krb5/buildlink3.mk"
CONFIGURE_ARGS+=	--with-krb5
PLIST.gssapi=		yes
.else
CONFIGURE_ARGS+=	--without-krb5
.endif

###
### WebDAV with PROPFIND/PROPPATCH, LOCK/UNLOCK
###
.if !empty(PKG_OPTIONS:Mwebdav)
.  include "../../databases/sqlite3/buildlink3.mk"
.  include "../../devel/libuuid/buildlink3.mk"
.  include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-webdav-props --with-webdav-locks
.endif
