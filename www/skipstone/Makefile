# $NetBSD: Makefile,v 1.24 2006/08/01 10:26:15 ghen Exp $

DISTNAME=		skipstone-0.9.6
CATEGORIES=		www
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.muhri.net/skipstone/
COMMENT=		Light and fast Gecko-based browser

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

USE_PKGLOCALEDIR=	yes

# it doesn't build with firefox headers, otherwise I'd make it an option
MOZILLA=		mozilla-gtk2

CONFIGURE_ARGS+=	--with-mozilla-includes=${PREFIX}/include/${MOZILLA}
CONFIGURE_ARGS+=	--with-mozilla-libs=${PREFIX}/lib/${MOZILLA}
CONFIGURE_ARGS+=	--enable-cvs-mozilla
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-localedir=${PREFIX}/${PKGLOCALEDIR}/locale
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${MOZILLA}

.include "options.mk"

.include "../../www/${MOZILLA}/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
