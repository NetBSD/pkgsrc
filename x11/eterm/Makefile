# $NetBSD: Makefile,v 1.6 2000/06/01 11:23:44 rh Exp $

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
USE_PKGLIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

pre-build:
	@if ${PKG_INFO} -qe 'eterm<0.8.9'; then				\
		${ECHO} "**** An older version of Eterm is installed";	\
		${ECHO} "**** ${PKGNAME} cannot be built with it installed."; \
		${ECHO} "**** Please delete it before building";	\
		${ECHO} "**** or use \"${MAKE} update\".";		\
		${FALSE};						\
	fi

post-extract:
	${LN} -sf ${WRKSRC} ${WRKDIR}/Eterm
	cd ${WRKDIR};							\
	for f in ${PIXMAP_FILES}; do					\
		${GZCAT} ${DISTDIR}/$$f | ${PAX} -r;			\
	done

.if ${OPSYS} == "NetBSD"
post-install:
	# Make Eterm setuid root so that utmp logging functions correctly.
	#
	${CHOWN} 0 ${PREFIX}/bin/Eterm
	${CHMOD} 4711 ${PREFIX}/bin/Eterm
.endif

.include "../../mk/bsd.pkg.mk"
