# $NetBSD: Makefile,v 1.24 2008/01/18 05:09:54 tnn Exp $
#

DISTNAME=	tinyproxy-1.6.2
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tinyproxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinyproxy.sourceforge.net/
COMMENT=	Lightweight HTTP/SSL proxy

GNU_CONFIGURE=	YES

RCD_SCRIPTS=		tinyproxy
PKG_SYSCONFSUBDIR=	tinyproxy

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE

TINYPROXY_USER?=	tinyproxy
TINYPROXY_GROUP?=	tinyproxy
PKG_GROUPS=		${TINYPROXY_GROUP}
PKG_USERS=		${TINYPROXY_USER}:${TINYPROXY_GROUP}
PKG_GROUPS_VARS+=	TINYPROXY_GROUP
PKG_USERS_VARS+=	TINYPROXY_USER
FILES_SUBST+=		TINYPROXY_USER=${TINYPROXY_USER:Q}
FILES_SUBST+=		TINYPROXY_GROUP=${TINYPROXY_GROUP:Q}

CONFIGURE_ARGS+=	--with-config=${PKG_SYSCONFDIR}/tinyproxy.conf
CONFIGURE_ARGS+=	--enable-transparent-proxy

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

.include "options.mk"

EGDIR=		${PREFIX}/share/examples/tinyproxy

CONF_FILES=	${EGDIR}/tinyproxy.conf.default ${PKG_SYSCONFDIR}/tinyproxy.conf

SUBST_CLASSES+=		docs
SUBST_STAGE.docs=	pre-configure
SUBST_FILES.docs=	doc/tinyproxy.8 doc/tinyproxy.conf
SUBST_SED.docs+=	-e 's,@TINYPROXY_USER@,${TINYPROXY_USER},g'
SUBST_SED.docs+=	-e 's,@TINYPROXY_GROUP@,${TINYPROXY_GROUP},g'
SUBST_SED.docs+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.docs+=	-e 's,@DATADIR@,${PREFIX}/share/tinyproxy,g'
SUBST_SED.docs+=	-e 's,@VARBASE@,${VARBASE},g'

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tinyproxy.conf \
		${EGDIR}/tinyproxy.conf.default
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tinyproxy
	${INSTALL_DATA} ${WRKSRC}/doc/filter-howto.txt \
		${PREFIX}/share/doc/tinyproxy/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
