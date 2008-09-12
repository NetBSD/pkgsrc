# $NetBSD: Makefile,v 1.1.1.1 2008/09/12 15:09:19 taca Exp $

DISTNAME=	squid-2.6.STABLE21
PKGNAME=	${DISTNAME:S/STABLE//}
PKGREVISION=	1
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
