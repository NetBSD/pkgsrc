# $NetBSD: Makefile,v 1.10 2000/07/11 10:47:19 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1996/11/18 09:55:42 asami Exp
#

DISTNAME=	xautolock-pl15
PKGNAME=	xautolock-1.15
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	eblood@cs.unr.edu

USE_IMAKE=	yes

post-install:
	cd ${WRKSRC}; \
	${INSTALL_MAN} xautolock.man ${X11PREFIX}/man/man1/xautolock.1

.include "../../mk/bsd.pkg.mk"
