# $NetBSD: Makefile,v 1.7 2012/10/28 06:30:18 asau Exp $

DISTNAME=	Kahua-1.0.1
PKGNAME=	${DISTNAME:C/Kahua/kahua/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.kahua.org/download/kahua/
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.kahua.org/
COMMENT=	Continuation-based framework to develop application service

MAKE_JOBS_SAFE=		no

DEPENDS+=	Gauche>=0.8.8:../../lang/gauche

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=--localstatedir=${VARBASE}
BUILD_DEFS+=	VARBASE

PKG_SYSCONFSUBDIR=	kahua
EGDIR=			${PREFIX}/share/examples/kahua
CONF_FILES=		${EGDIR}/kahua.conf ${PKG_SYSCONFDIR}/kahua.conf

USE_TOOLS+=	gzip makeinfo
INFO_FILES=	yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	sysconfdir=${DESTDIR}${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	localstatedir=${DESTDIR}${VARBASE}/kahua
INSTALL_MAKE_FLAGS+=	KAHUA_STATICDIR=${DESTDIR}${VARBASE}/kahua/static
INSTALL_MAKE_FLAGS+=	KAHUA_CGI_DIR=${DESTDIR}${PREFIX}/libexec/kahua
INSTALL_MAKE_FLAGS+=	KAHUA_CGILOG_DIR=${DESTDIR}${VARBASE}/kahua/cgilog

.include "../../mk/bsd.pkg.mk"
