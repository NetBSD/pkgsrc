# $NetBSD: Makefile,v 1.1.1.1 2007/05/27 02:58:40 obache Exp $
#

DISTNAME=	mimetex
PKGNAME=	${DISTNAME}-1.64
CATEGORIES=	www math graphics
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/mimetex/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.forkosh.com/mimetex.html
COMMENT=	CGI to convert LaTeX math expression to GIF image

USE_LANGUAGES=	c

WRKSRC=		${WRKDIR}

do-build:
		cd ${WRKSRC:Q} && \
		env ${MAKE_ENV} ${CC} -DAA mimetex.c gifsave.c -lm \
			-o mimetex.cgi

do-install:
		${INSTALL_PROGRAM} ${WRKSRC:Q}/mimetex.cgi ${PREFIX}/libexec/cgi-bin

.include "../../mk/bsd.pkg.mk"
