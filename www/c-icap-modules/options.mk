# $NetBSD: options.mk,v 1.3 2015/06/12 23:40:16 taca Exp $

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
CONF_FILES+=	${EGDIR}/virus_scan.conf.default ${PKG_SYSCONFDIR}/virus_scan.conf
CONF_FILES+=	${EGDIR}/clamd_mod.conf.default ${PKG_SYSCONFDIR}/clamd_mod.conf
CONF_FILES+=	${EGDIR}/clamav_mod.conf.default ${PKG_SYSCONFDIR}/clamav_mod.conf

.  include "../../security/clamav/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-clamav
.endif
