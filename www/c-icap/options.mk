# $NetBSD: options.mk,v 1.2 2023/07/09 09:50:47 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.c-icap
PKG_SUPPORTED_OPTIONS=	bzip2 brotli bdb ldap memcached openssl perl pcre zlib
PKG_SUGGESTED_OPTIONS=	bdb ldap openssl perl zlib

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		bdb ldap memcached perl

.if !empty(PKG_OPTIONS:Mbdb)
PLIST.bdb=		yes
BDB_ACCEPTED=		db5 db4
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
.  include "../../mk/bdb.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if !empty(PKG_OPTIONS:Mbrotli)
CONFIGURE_ARGS+=	--with-brotli
.  include "../../archivers/brotli/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-brotli
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
CONFIGURE_ARGS+=	--with-bzlib
.  include "../../archivers/bzip2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-bzlib
.endif

.if !empty(PKG_OPTIONS:Mmemcached)
PLIST.memcached=	yes
CONFIGURE_ARGS+=	--with-memcached
.  include "../../devel/libmemcached/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-memcached
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
SUBST_CLASSES+=		fix-ldap
SUBST_STAGE.fix-ldap=	post-configure
SUBST_MESSAGE.fix-ldap=	Fixing LDAP.
SUBST_FILES.fix-ldap=	modules/Makefile
SUBST_SED.fix-ldap=	-e 's,-DLDAP_DEPRECATED,,g'
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mperl)
PLIST.perl=		yes
USE_TOOLS+=		perl:build
CONFIGURE_ARGS+=	--with-perl
.  include "../../lang/perl5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=	--with-pcre
.  include "../../devel/pcre/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--with-zlib
.  include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zlib
.endif
