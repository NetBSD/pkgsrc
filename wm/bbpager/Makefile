# $NetBSD: Makefile,v 1.16 2006/07/22 04:46:19 rillig Exp $
#

DISTNAME=	bbpager-0.3.1
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/available.phtml
COMMENT=	Pager for the blackbox window manager

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbpager.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bbpager.bb.5 ${PREFIX}/man/man5

.include "../../mk/bsd.pkg.mk"
