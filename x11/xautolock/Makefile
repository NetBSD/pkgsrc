# $NetBSD: Makefile,v 1.11 2001/02/17 17:06:59 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1996/11/18 09:55:42 asami Exp
#

DISTNAME=	xautolock-pl15
PKGNAME=	xautolock-1.15
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	eblood@cs.unr.edu
COMMENT=	Activate xlock after a user defined time of inactivity

USE_IMAKE=	yes

post-install:
	cd ${WRKSRC}; \
	${INSTALL_MAN} xautolock.man ${X11PREFIX}/man/man1/xautolock.1

.include "../../mk/bsd.pkg.mk"
