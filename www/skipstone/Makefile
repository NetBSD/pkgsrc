# $NetBSD: Makefile,v 1.13 2002/05/28 23:31:06 taya Exp $

DISTNAME=	skipstone-0.8.2
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muhri.net/skipstone/
COMMENT=	GTK+ web browser that embeds Mozilla's renderer

DEPENDS+=	mozilla>=1.0rc3:../../www/mozilla

EVAL_PREFIX+=	MOZ_DIR=mozilla
MOZ_INCDIR=     ${MOZ_DIR}/include/mozilla
MOZ_LIBDIR=     ${MOZ_DIR}/lib/mozilla
USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-mozilla-includes=${MOZ_INCDIR} \
		--with-mozilla-libs=${MOZ_LIBDIR}
LDFLAGS+= -Wl,-R${MOZ_LIBDIR}

.include "../../mk/bsd.pkg.mk"
