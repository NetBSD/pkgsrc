# $NetBSD: Makefile,v 1.13 2006/03/16 22:48:42 wiz Exp $

DISTNAME=	cgicc-3.2.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=cgicc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cgicc/cgicc.html
COMMENT=	C++ compliant CGI applications libraries

USE_LANGUAGES=		c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-demos

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc*)
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.endif

.include "../../mk/bsd.pkg.mk"
