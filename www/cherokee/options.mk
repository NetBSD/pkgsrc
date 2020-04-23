# $NetBSD: options.mk,v 1.3 2020/04/23 15:46:01 nia Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.cherokee
PKG_SUPPORTED_OPTIONS+=		geoip ffmpeg inet6 ldap mysql pam ssl threads
PKG_SUGGESTED_OPTIONS+=		inet6 pam ssl threads

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ffmpeg geoip ldap mysql pam ssl

###
### Threading support.
###
.if !empty(PKG_OPTIONS:Mthreads)
.include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pthread
.else
CONFIGURE_ARGS+=	--disable-pthread
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
### SSL support.
###
.if !empty(PKG_OPTIONS:Mssl)
PLIST.ssl=		yes
CONFIGURE_ARGS+=	--with-libssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libssl
.endif

###
### Allow using LDAP for "basic" authentication.
###
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

###
### Allow using MySQL for virtual host configuration.
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=		yes
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

###
### GeoIP support
###
.if !empty(PKG_OPTIONS:Mgeoip)
PLIST.geoip=		yes
CONFIGURE_ARGS+=	--with-geoip=${BUILDLINK_PREFIX.GeoIP}
.include "../../net/GeoIP/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-geoip
.endif

###
### FFMpeg support
###
.if !empty(PKG_OPTIONS:Mffmpeg)
PLIST.ffmpeg=		yes
CONFIGURE_ARGS+=	--with-ffmpeg=${BUILDLINK_PREFIX.ffmpeg}
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

###
### PAM support
###
.if !empty(PKG_OPTIONS:Mpam)
PLIST.pam=		yes
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
.else
CONFIGURE_ARGS+=	--disable-pam
.endif
