# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:25 tv Exp $

DISTNAME=	cgicc-3.1.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=cgicc/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://www.gnu.org/software/cgicc/cgicc.html
COMMENT=	C++ compliant CGI applications libraries

USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

INFO_FILES=	cgicc.info

LTCONFIG_OVERRIDE=	${WRKSRC}/support/ltconfig ${WRKSRC}/example/ltconfig

.include "../../mk/bsd.pkg.mk"
