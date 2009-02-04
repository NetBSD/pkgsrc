# $NetBSD: Makefile,v 1.7 2009/02/04 12:21:27 taca Exp $

DISTNAME=	squid-3.0.STABLE13
PKGNAME=	${DISTNAME:S/STABLE//}
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v3/3.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	destdir

.include "../../www/squid/Makefile.squid"
.include "../../www/squid/options.mk"
.include "../../mk/bsd.pkg.mk"
