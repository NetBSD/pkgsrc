# $NetBSD: Makefile,v 1.7 2002/12/27 14:36:01 cjep Exp $
#

DISTNAME=	cgilib-0.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.infodrom.north.de/pub/people/joey/cgilib/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.infodrom.north.de/cgilib/
COMMENT=	Common gateway interface library

USE_LIBTOOL=	yes

USE_RMAN=	yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
MAKE_FLAGS+=	NROFF="man -l"
.endif

.include "../../mk/bsd.pkg.mk"
