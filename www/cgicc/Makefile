# $NetBSD: Makefile,v 1.6 2004/01/24 15:23:46 grant Exp $

DISTNAME=	cgicc-3.1.5
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
