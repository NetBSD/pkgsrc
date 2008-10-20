# $NetBSD: Makefile,v 1.2 2008/10/20 03:11:03 taca Exp $

DISTNAME=	squid-2.6.STABLE22
PKGNAME=	${DISTNAME:S/STABLE//}
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	destdir

.include "../../www/squid/Makefile.squid"
.include "../../www/squid/options.mk"
.include "../../mk/bsd.pkg.mk"
