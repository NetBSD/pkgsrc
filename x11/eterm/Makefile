# $NetBSD: Makefile,v 1.4 1999/10/28 00:31:57 jlam Exp $

DISTNAME=		Eterm-0.8.9
PKGNAME=		eterm-0.8.9
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.eterm.org/pub/Eterm/ \
			ftp://alien.eterm.org/pub/Eterm/ \
			ftp://ftp.themes.org/pub/enlightenment/eterm/ \
			ftp://ftp.dti.ad.jp/pub/X/Eterm/
DISTFILES=		${ETERM_SRCS} ${PIXMAP_FILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.eterm.org/

DEPENDS+=		imlib-*:../../graphics/imlib

EXTRACT_ONLY=		${ETERM_SRCS}
ETERM_SRCS=		${DISTNAME}${EXTRACT_SUFX}
PIXMAP_FILES=		Eterm-bg-scale-1.tar.gz Eterm-bg-scale-2.tar.gz \
			Eterm-bg-tile.tar.gz

USE_X11BASE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-extract:
	${LN} -sf ${WRKSRC} ${WRKDIR}/Eterm
.for FILE in ${PIXMAP_FILES}
	cd ${WRKDIR}; ${PAX} -zrf ${DISTDIR}/${FILE}
.endfor

post-install:
	# Make Eterm setuid root so that utmp logging functions correctly.
	#
	${CHOWN} 0 ${PREFIX}/bin/Eterm
	${CHMOD} 4711 ${PREFIX}/bin/Eterm

.include "../../mk/bsd.pkg.mk"
