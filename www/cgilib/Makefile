# $NetBSD: Makefile,v 1.4 2001/05/03 14:23:36 jlam Exp $
#

DISTNAME=	cgilib-0.5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.infodrom.north.de/pub/people/joey/cgilib/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.infodrom.north.de/cgilib/
COMMENT=	Common gateway interface library

.include "../../mk/bsd.pkg.mk"

.if !exists(${X11BASE}/bin/rman)
BUILD_DEPENDS+=	rman>=3.0.9:../../textproc/rman
.endif
