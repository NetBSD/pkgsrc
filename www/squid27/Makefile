# $NetBSD: Makefile,v 1.17 2012/10/03 21:59:04 wiz Exp $

DISTNAME=	squid-2.7.STABLE9
PKGREVISION=	3

PKGNAME=	${DISTNAME:S/STABLE//}
CATEGORIES=	www
MASTER_SITES=	${SQUID_MASTER_SITES} \
		http://www.squid-cache.org/Versions/v2/2.7/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
MESSAGE_SRC=		../squid/MESSAGE MESSAGE

.include "../../www/squid/Makefile.squid"
.include "../../www/squid/options.mk"
.include "../../mk/bsd.pkg.mk"
