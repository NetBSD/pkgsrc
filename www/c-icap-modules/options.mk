# $NetBSD: options.mk,v 1.1.1.1 2011/05/11 04:30:06 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.c-icap
PKG_SUPPORTED_OPTIONS=	bdb clamav
PKG_SUGGESTED_OPTIONS=	bdb clamav

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		bdb clamav

.if !empty(PKG_OPTIONS:Mbdb)
PLIST.bdb=		yes
BDB_ACCEPTED=		db5 db4
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
.  include "../../mk/bdb.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if !empty(PKG_OPTIONS:Mclamav)
PLIST.clamav=		yes
CONFIGURE_ARGS+=	--with-clamav
CONF_FILES+=	${EGDIR}/srv_clamav.conf.default ${PKG_SYSCONFDIR}/srv_clamav.conf
.  include "../../security/clamav/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-clamav
.endif
