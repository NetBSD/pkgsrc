# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 15:59:44 skrll Exp $
#

DISTNAME=	kdelibs-2.1
CATEGORIES=	x11 kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Support libraries for the KDE integrated X11 desktop

DEPENDS+=		tiff-*:../../graphics/tiff
DEPENDS+=		qt2-libs>=2.2.4:../../x11/qt2-libs
DEPENDS+=		libaudiofile-*:../../audio/libaudiofile
DEPENDS+=		jade>=1.2.1:../../textproc/jade

.include "../../x11/kde2/Makefile.part2"

LTCONFIG_OVERRIDE+=	${WRKSRC}/ksgmltools/ltconfig

CONFIGURE_ENV+=		LIBS="-Wl,--export-dynamic"

MKDIRS=	share/kde/icons/locolor/32x32/actions/kde \
	share/kde/icons/locolor/22x22/mimetypes \
	share/kde/icons/locolor/22x22/filesystems \
	share/kde/icons/locolor/22x22/actions/kde \
	share/kde/icons/hicolor/22x22/mimetypes \
	share/kde/icons/hicolor/22x22/filesystems

post-install:
	for d in ${MKDIRS}; do \
		${INSTALL_DATA_DIR} ${PREFIX}/$$d; \
	done

.include "../../mk/bsd.pkg.mk"
