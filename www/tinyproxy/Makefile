# $NetBSD: Makefile,v 1.29 2012/12/12 13:01:23 wiz Exp $
#

DISTNAME=	tinyproxy-1.8.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tinyproxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinyproxy.sourceforge.net/
COMMENT=	Lightweight HTTP/SSL proxy
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

RCD_SCRIPTS=		tinyproxy
PKG_SYSCONFSUBDIR=	tinyproxy

.include "../../mk/bsd.prefs.mk"

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
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
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-transparent-proxy

.include "options.mk"

EGDIR=		${PREFIX}/share/examples/tinyproxy

CONF_FILES=	${EGDIR}/tinyproxy.conf.default ${PKG_SYSCONFDIR}/tinyproxy.conf

SUBST_CLASSES+=		docs
SUBST_STAGE.docs=	pre-configure
SUBST_FILES.docs=	docs/man5/tinyproxy.conf.txt.in docs/man8/tinyproxy.txt.in etc/tinyproxy.conf.in
SUBST_SED.docs+=	-e 's,@TINYPROXY_USER@,${TINYPROXY_USER},g'
SUBST_SED.docs+=	-e 's,@TINYPROXY_GROUP@,${TINYPROXY_GROUP},g'
SUBST_SED.docs+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.docs+=	-e 's,@VARBASE@,${VARBASE},g'

INSTALLATION_DIRS=	${EGDIR} share/doc/tinyproxy

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/tinyproxy.conf \
		${DESTDIR}${EGDIR}/tinyproxy.conf.default
	${INSTALL_DATA} ${WRKSRC}/docs/filter-howto.txt \
		${DESTDIR}${PREFIX}/share/doc/tinyproxy/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
