# $NetBSD: Makefile,v 1.7 2003/07/21 17:33:59 martti Exp $
#

DISTNAME=	bbpager-0.3.1
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://bbtools.thelinuxcommunity.org/sources/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bbtools.thelinuxcommunity.org/available.phtml
COMMENT=	Pager for the blackbox window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbpager.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bbpager.bb.5 ${PREFIX}/man/man5

.include "../../mk/bsd.pkg.mk"
