# $NetBSD: Makefile,v 1.15.2.1 2004/01/01 22:56:24 agc Exp $
#

DISTNAME=		xfstt-1.6
CATEGORIES=		x11 net fonts
MASTER_SITES=		http://download.berlios.de/xfstt/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://developer.berlios.de/projects/xfstt/
COMMENT=		TrueType font server for X11

USE_PKGINSTALL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

# There isn't really any l10n yet, only some preliminary i18n support.
CONFIGURE_ARGS+=	--disable-nls

CXXFLAGS+=		-fomit-frame-pointer -ffast-math

RCD_SCRIPTS=		xfstt

post-patch:
	@( \
	cd ${WRKSRC} ; \
	for f in src/perftest.cc src/xfstt.cc doc/xfstt.1x; \
	do \
	    ${MV} $$f $$f.orig ; \
	    ${SED} ${FILES_SUBST_SED} $$f.orig > $$f ; \
	done ; \
	)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xfstt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xfstt.1x ${PREFIX}/man/man1/xfstt.1
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/TrueType
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xfstt
	cd ${WRKSRC} && (				\
	${INSTALL_DATA} doc/FAQ CHANGES TODO THANKS	\
		${PREFIX}/share/doc/xfstt/ ;		\
	${INSTALL_DATA} doc/examples/font.properties	\
		 ${PREFIX}/share/examples/xfstt/	\
	)

.include "../../mk/bsd.pkg.mk"
