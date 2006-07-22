# $NetBSD: Makefile,v 1.14 2006/07/22 04:46:19 rillig Exp $

DISTNAME=	cgicc-3.2.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=cgicc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cgicc/cgicc.html
COMMENT=	C++ compliant CGI applications libraries

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-demos

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc*)
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.endif

.include "../../mk/bsd.pkg.mk"
