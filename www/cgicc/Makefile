# $NetBSD: Makefile,v 1.4 2003/08/07 10:19:39 seb Exp $

DISTNAME=	cgicc-3.1.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=cgicc/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://www.gnu.org/software/cgicc/cgicc.html
COMMENT=	C++ compliant CGI applications libraries

USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

USE_NEW_TEXINFO=	YES
INFO_FILES=	cgicc.info

LTCONFIG_OVERRIDE=	${WRKSRC}/support/ltconfig ${WRKSRC}/example/ltconfig

.include "../../mk/bsd.pkg.mk"
