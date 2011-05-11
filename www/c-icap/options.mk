# $NetBSD: options.mk,v 1.1.1.1 2011/05/11 04:29:18 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.c-icap
PKG_SUPPORTED_OPTIONS=	bdb ldap perl
PKG_SUGGESTED_OPTIONS=	bdb ldap perl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		bdb ldap perl

.if !empty(PKG_OPTIONS:Mbdb)
PLIST.bdb=		yes
BDB_ACCEPTED=		db5 db4
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
.  include "../../mk/bdb.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=		yes
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mperl)
PLIST.perl=		yes
USE_TOOLS+=		perl:build
CONFIGURE_ARGS+=	--with-perl
.  include "../../lang/perl5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-perl
.endif
