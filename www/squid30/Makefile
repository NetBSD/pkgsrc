# $NetBSD: Makefile,v 1.22 2010/03/16 13:39:06 taca Exp $

DISTNAME=	squid-3.0.STABLE25
PKGNAME=	${DISTNAME:S/STABLE//}
CATEGORIES=	www
MASTER_SITES=	${SQUID_MASTER_SITES} \
		http://www.squid-cache.org/Versions/v3/3.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes

.include "../../www/squid/Makefile.squid"
.include "../../www/squid/options.mk"
.include "../../mk/bsd.pkg.mk"
