# $NetBSD: Makefile,v 1.12 2002/05/26 12:10:13 taya Exp $

DISTNAME=	skipstone-0.8.2
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muhri.net/skipstone/
COMMENT=	GTK+ web browser that embeds Mozilla's renderer

DEPENDS+=	mozilla>=1.0rc3:../../www/mozilla

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-mozilla-includes=${PREFIX}/include/mozilla \
		--with-mozilla-libs=${PREFIX}/lib/mozilla

.include "../../mk/bsd.pkg.mk"
