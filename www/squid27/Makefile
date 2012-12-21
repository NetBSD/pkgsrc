# $NetBSD: Makefile,v 1.16.8.1 2012/12/21 10:43:50 tron Exp $

DISTNAME=	squid-2.7.STABLE9
PKGREVISION=	5

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

CONFIGURE_ARGS+=	--enable-auth=basic,digest,ntlm

.include "../../www/squid/options.mk"
.include "../../mk/bsd.pkg.mk"
