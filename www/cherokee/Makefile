# $NetBSD: Makefile,v 1.13 2010/03/12 13:45:42 jmmv Exp $
#

DISTNAME=	cherokee-0.5.3
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://www.cherokee-project.com/download/0.5/0.5.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherokee-project.com/
COMMENT=	Flexible and fast web server

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-wwwroot=${PREFIX}/share/cherokee

PKGCONFIG_OVERRIDE=	cherokee.pc.in

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR:Q}
OWN_DIRS=		${PKG_SYSCONFDIR}/cherokee
OWN_DIRS+=		${PKG_SYSCONFDIR}/cherokee/mods-enabled
OWN_DIRS+=		${PKG_SYSCONFDIR}/cherokee/sites-enabled
OWN_DIRS+=		${VARBASE}/log
OWN_DIRS+=		${VARBASE}/run
EGDIR=			${PREFIX}/share/examples/cherokee
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}
CONF_FILES=
.for f in		advanced.conf \
			cherokee.conf \
			icons.conf \
			mime.compression.types \
			mime.types
CONF_FILES+=		${EGDIR}/cherokee/${f} ${PKG_SYSCONFDIR}/cherokee/${f}
.endfor
CONF_FILES+=		${EGDIR}/cherokee/sites-available/default \
			${PKG_SYSCONFDIR}/cherokee/sites-enabled/default

RCD_SCRIPTS=		cherokee

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-configure
SUBST_MESSAGE.varbase=	Fixing references to local state directory.
SUBST_SED.varbase=	-e 's|/var/|${VARBASE}/|g'
SUBST_FILES.varbase=	cherokee.conf.sample.pre
SUBST_FILES.varbase+=	http-cherokee.xml
SUBST_FILES.varbase+=	cherokee-logrotate.1
SUBST_FILES.varbase+=	sites-default.sample.pre

PKG_OPTIONS_VAR=		PKG_OPTIONS.cherokee
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl
PKG_SUGGESTED_OPTIONS+=		inet6 gnutls
PKG_SUPPORTED_OPTIONS+=		inet6
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--enable-tls=gnutls
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
CONF_FILES+=		${EGDIR}/cherokee/mods-available/ssl \
			${PKG_SYSCONFDIR}/cherokee/mods-enabled/ssl
.elif !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--enable-tls=openssl
.include "../../security/openssl/buildlink3.mk"
CONF_FILES+=		${EGDIR}/cherokee/mods-available/ssl \
			${PKG_SYSCONFDIR}/cherokee/mods-enabled/ssl
.else
CONFIGURE_ARGS+=	--disable-tls
.endif

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}/pam.d

.include "../../mk/bsd.pkg.mk"
