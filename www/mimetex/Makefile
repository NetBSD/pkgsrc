# $NetBSD: Makefile,v 1.3 2007/12/17 10:33:56 obache Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	libexec/cgi-bin

do-build:
		cd ${WRKSRC:Q} && \
		env ${MAKE_ENV} ${CC} -DAA mimetex.c gifsave.c -lm \
			-o mimetex.cgi

do-install:
		${INSTALL_PROGRAM} ${WRKSRC:Q}/mimetex.cgi ${DESTDIR}${PREFIX}/libexec/cgi-bin

.include "../../mk/bsd.pkg.mk"
