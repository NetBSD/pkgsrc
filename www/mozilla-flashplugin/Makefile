# $NetBSD: Makefile,v 1.1.1.1 2002/04/10 04:22:19 itojun Exp $
#

DISTNAME=	flash-0.4.10
PKGNAME=	mozilla-flashplugin-0.4.10
CATEGORIES=	www
MASTER_SITES=	http://www.swift-tools.com/Flash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.swift-tools.com/Flash/
COMMENT=	GPL macromedia flash player plugin

USE_X11BASE=	yes

STRIPFLAG=
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Plugin/npflash.so ${X11BASE}/lib/mozilla/plugins

.include "../../mk/bsd.pkg.mk"
