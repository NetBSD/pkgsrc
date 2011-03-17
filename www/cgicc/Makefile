# $NetBSD: Makefile,v 1.17 2011/03/17 14:48:50 adam Exp $

DISTNAME=	cgicc-3.2.9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=cgicc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cgicc/cgicc.html
COMMENT=	C++ compliant CGI applications libraries
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-demos

BUILD_DIRS=		cgicc support

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc*)
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.endif

.include "../../mk/bsd.pkg.mk"
