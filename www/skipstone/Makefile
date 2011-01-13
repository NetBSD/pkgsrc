# $NetBSD: Makefile,v 1.33 2011/01/13 13:39:41 wiz Exp $

DISTNAME=		skipstone-0.9.6
PKGREVISION=		7
CATEGORIES=		www
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.muhri.net/skipstone/
COMMENT=		Light and fast Gecko-based browser

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-mozilla-includes=${PREFIX}/include/${MOZILLA}
CONFIGURE_ARGS+=	--with-mozilla-libs=${PREFIX}/lib/${MOZILLA}
CONFIGURE_ARGS+=	--enable-cvs-mozilla
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-localedir=${PREFIX}/${PKGLOCALEDIR}/locale
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${MOZILLA}

BROKEN=			Package doesn't build with xulrunner

.include "options.mk"

.include "../../devel/xulrunner/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
