# $NetBSD: Makefile,v 1.4 2008/11/05 13:25:12 obache Exp $
#

DISTNAME=	mimetex
PKGNAME=	${DISTNAME}-1.70
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
