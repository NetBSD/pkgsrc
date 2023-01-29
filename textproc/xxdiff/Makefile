# $NetBSD: Makefile,v 1.8 2023/01/29 21:17:55 ryoon Exp $

PKGREVISION= 6
.include "../../textproc/xxdiff/Makefile.common"

COMMENT=	Graphical file comparator and merge tool

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex gmake

HAS_CONFIGURE=		yes
CONFIG_SHELL=		# empty
CONFIGURE_DIRS=		src
CONFIGURE_SCRIPT=	${MAKE_PROGRAM}
CONFIGURE_ARGS=		-f Makefile.bootstrap

BUILD_DIRS=	src
BUILD_TARGET=	doc.h all

INSTALLATION_DIRS+=	bin ${XXDIFFDOCDIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xxdiff ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/xxdiff.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/xxdiff-doc.html ${DESTDIR}${PREFIX}/${XXDIFFDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/xxdiff-integration.html ${DESTDIR}${PREFIX}/${XXDIFFDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/xxdiff-secrets.html ${DESTDIR}${PREFIX}/${XXDIFFDOCDIR}

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
