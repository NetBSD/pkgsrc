# $NetBSD: Makefile,v 1.1.1.1 2003/02/15 19:14:09 jschauma Exp $
#

DISTNAME=	larswm-7.2.8
CATEGORIES=	x11 wm
MASTER_SITES=	http://www-personal.umich.edu/~larsb/larswm/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www-personal.umich.edu/~larsb/larswm/
COMMENT=	9wm-like window manager

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DOCFILES=	keyboard_refcard.pdf mouse_refcard.pdf

USE_IMAKE=	YES

post-build:
	@${RM} -f ${WRKSRC}/*.html

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/larswm
.for pdf in ${DOCFILES}
	${INSTALL_DATA} ${DISTDIR}/${pdf} ${PREFIX}/share/doc/larswm
.endfor

.include "../../mk/bsd.pkg.mk"
