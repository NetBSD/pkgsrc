# $NetBSD: Makefile,v 1.12 2010/02/14 13:27:52 taca Exp $

DISTNAME=	squid-2.7.STABLE7
PKGNAME=	${DISTNAME:S/STABLE//}
PKGREVISION=	3
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
PKG_DESTDIR_SUPPORT=	destdir
MESSAGE_SRC=		../squid/MESSAGE MESSAGE

.include "../../www/squid/Makefile.squid"
.include "../../www/squid/options.mk"
.include "../../mk/bsd.pkg.mk"
