# $NetBSD: Makefile,v 1.8 2004/01/23 11:53:13 jlam Exp $
#

DISTNAME=	cgilib-0.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.infodrom.north.de/pub/people/joey/cgilib/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.infodrom.north.de/cgilib/
COMMENT=	Common gateway interface library

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_RMAN=	yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
MAKE_FLAGS+=	NROFF="man -l"
.endif

.include "../../mk/bsd.pkg.mk"
