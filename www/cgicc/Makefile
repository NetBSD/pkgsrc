# $NetBSD: Makefile,v 1.2 2002/02/18 15:14:44 seb Exp $

DISTNAME=	cgicc-3.1.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=cgicc/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://www.gnu.org/software/cgicc/cgicc.html
COMMENT=	c++ compliant CGI applications libraries

USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

INFO_FILES=	cgicc.info

LTCONFIG_OVERRIDE=	${WRKSRC}/support/ltconfig ${WRKSRC}/example/ltconfig

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
