# $NetBSD: Makefile,v 1.1.1.1 2001/03/16 14:15:53 wiz Exp $
#

DISTNAME=	xwit-3.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	seb@pbox.org
COMMENT=	Utility for calling X11 functions from the shell

USE_IMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xwit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xwit.man ${PREFIX}/man/man1/xwit.1
	${INSTALL_MAN} ${WRKSRC}/xwit.0 ${PREFIX}/man/cat1/xwit.0

.include "../../mk/bsd.pkg.mk"
