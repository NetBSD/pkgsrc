# $NetBSD: Makefile,v 1.13 2005/06/01 18:03:24 jlam Exp $
#

DISTNAME=	bbpager-0.3.1
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/available.phtml
COMMENT=	Pager for the blackbox window manager

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbpager.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bbpager.bb.5 ${PREFIX}/man/man5

.include "../../mk/bsd.pkg.mk"
