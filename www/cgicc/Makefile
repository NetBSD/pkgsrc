# $NetBSD: Makefile,v 1.9 2005/08/20 11:06:07 grant Exp $

DISTNAME=	cgicc-3.1.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=cgicc/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://www.gnu.org/software/cgicc/cgicc.html
COMMENT=	C++ compliant CGI applications libraries

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

INFO_FILES=	cgicc.info

LTCONFIG_OVERRIDE=	${WRKSRC}/support/ltconfig ${WRKSRC}/example/ltconfig

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc)
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.endif

.include "../../mk/bsd.pkg.mk"
