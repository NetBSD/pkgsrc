# $NetBSD: Makefile,v 1.9 2001/04/28 11:07:34 zuntum Exp $

DISTNAME=		Eterm-0.8.10
PKGNAME=		eterm-0.8.10
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.eterm.org/pub/Eterm/ \
			ftp://alien.eterm.org/pub/Eterm/ \
			ftp://ftp.themes.org/pub/enlightenment/eterm/ \
			ftp://ftp.dti.ad.jp/pub/X/Eterm/
DISTFILES=		${ETERM_SRCS} ${PIXMAP_FILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.eterm.org/
COMMENT=		Enlightened terminal emulator for the X Window System

DEPENDS+=		imlib-*:../../graphics/imlib

EXTRACT_ONLY=		${ETERM_SRCS}
ETERM_SRCS=		${DISTNAME}${EXTRACT_SUFX}
PIXMAP_FILES=		Eterm-bg-scale-1.tar.gz Eterm-bg-scale-2.tar.gz \
			Eterm-bg-tile.tar.gz

USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

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
