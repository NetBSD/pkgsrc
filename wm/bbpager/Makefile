# $NetBSD: Makefile,v 1.3 2002/12/14 00:21:36 jschauma Exp $
#

DISTNAME=	bbpager-0.3.1
CATEGORIES=	x11 wm
MASTER_SITES=	http://bbtools.thelinuxcommunity.org/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bbtools.thelinuxcommunity.org/available.phtml
COMMENT=	pager for the blackbox window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11BASE=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbpager.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bbpager.bb.5 ${PREFIX}/man/man5

.include "../../mk/bsd.pkg.mk"
