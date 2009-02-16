# $NetBSD: Makefile,v 1.16 2009/02/16 19:16:57 joerg Exp $
#

DISTNAME=	cgilib-0.5
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.infodrom.org/projects/cgilib/download/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.infodrom.org/projects/cgilib/
COMMENT=	Common gateway interface library

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man5
USE_LIBTOOL=	yes
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
