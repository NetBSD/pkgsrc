# $NetBSD: Makefile,v 1.16 2003/03/14 19:38:03 jlam Exp $

DISTNAME=	skipstone-0.8.3
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muhri.net/skipstone/
COMMENT=	GTK+ web browser that embeds Mozilla's renderer

BROKEN=		Does not compile. No new version currently available.

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-mozilla-includes=${BUILDLINK_PREFIX.mozilla}/include/mozilla \
		--with-mozilla-libs=${BUILDLINK_PREFIX.mozilla}/lib/mozilla
LDFLAGS+=	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.mozilla}/lib/mozilla

# for mozilla-stable (1.0 series)
#CONFIGURE_ARGS=	--prefix=${PREFIX} \
#		--with-mozilla-includes=${BUILDLINK_PREFIX.mozilla-stable}/include/mozilla-stable \
#		--with-mozilla-libs=${BUILDLINK_PREFIX.mozilla-stable}/lib/mozilla-stable
#LDFLAGS+=	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.mozilla-stable}/lib/mozilla-stable

#.include "../../www/mozilla-stable/buildlink2.mk"
.include "../../www/mozilla/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
