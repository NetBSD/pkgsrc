# $NetBSD: Makefile,v 1.27 2006/02/05 23:11:47 joerg Exp $
#

DISTNAME=		xfstt-1.6
PKGREVISION=		4
CATEGORIES=		x11 net fonts
MASTER_SITES=		http://download.berlios.de/xfstt/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://developer.berlios.de/projects/xfstt/
COMMENT=		TrueType font server for X11

USE_X11BASE=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

# There isn't really any l10n yet, only some preliminary i18n support.
CONFIGURE_ARGS+=	--disable-nls

CXXFLAGS+=		-fomit-frame-pointer -ffast-math

RCD_SCRIPTS=		xfstt
INSTALLATION_DIRS=	bin man/man1

.include "../../mk/x11.buildlink3.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	doc/FAQ doc/xfstt.1x
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xfstt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xfstt.1x ${PREFIX}/man/man1/xfstt.1
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/TTF
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xfstt
	cd ${WRKSRC} && (				\
	${INSTALL_DATA} doc/FAQ CHANGES TODO THANKS	\
		${PREFIX}/share/doc/xfstt/ ;		\
	${INSTALL_DATA} doc/examples/font.properties	\
		 ${PREFIX}/share/examples/xfstt/	\
	)

.include "../../mk/bsd.pkg.mk"
