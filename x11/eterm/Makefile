# $NetBSD: Makefile,v 1.16 2002/08/25 21:52:35 jlam Exp $

DISTNAME=		Eterm-0.8.10
PKGNAME=		eterm-0.8.10
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.eterm.org/pub/Eterm/ \
			ftp://alien.eterm.org/pub/Eterm/ \
			ftp://ftp.dti.ad.jp/pub/X/Eterm/
DISTFILES=		${ETERM_SRCS} ${PIXMAP_FILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.eterm.org/
COMMENT=		Enlightened terminal emulator for the X Window System

EXTRACT_ONLY=		${ETERM_SRCS}
ETERM_SRCS=		${DISTNAME}${EXTRACT_SUFX}
PIXMAP_FILES=		Eterm-bg-scale-1.tar.gz Eterm-bg-scale-2.tar.gz \
			Eterm-bg-tile.tar.gz

USE_BUILDLINK2=		yes
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

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
