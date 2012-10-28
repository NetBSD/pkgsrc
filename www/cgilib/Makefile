# $NetBSD: Makefile,v 1.18 2012/10/28 06:30:12 asau Exp $
#

DISTNAME=	cgilib-0.5
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.infodrom.org/projects/cgilib/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.infodrom.org/projects/cgilib/
COMMENT=	Common gateway interface library

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man5
USE_LIBTOOL=	yes
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
