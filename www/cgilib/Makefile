# $NetBSD: Makefile,v 1.15 2007/07/09 21:51:30 minskim Exp $
#

DISTNAME=	cgilib-0.5
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.infodrom.org/projects/cgilib/download/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.infodrom.org/projects/cgilib/
COMMENT=	Common gateway interface library

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man5
USE_LIBTOOL=	yes
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
