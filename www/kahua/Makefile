# $NetBSD: Makefile,v 1.1.1.1 2007/01/19 13:45:35 uebayasi Exp $

DISTNAME=	Kahua-1.0.1
PKGNAME=	${DISTNAME:C/Kahua/kahua/}
CATEGORIES=	www
MASTER_SITES=	http://www.kahua.org/download/kahua/
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.kahua.org/
COMMENT=	Continuation-based framework to develop application service

DEPENDS+=	Gauche>=0.8.8:../../lang/gauche

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=--localstatedir=${DESTDIR:Q}/var

USE_TOOLS+=	gzip makeinfo
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
