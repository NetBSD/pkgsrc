# $NetBSD: Makefile,v 1.37 2024/01/30 14:22:43 ryoon Exp $

DISTNAME=	qwt-6.1.6
PKGNAME=	qwt6-qt5-6.1.6
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qwt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qwt.sourceforge.io/
COMMENT=	Qt widget library for technical purposes
LICENSE=	gnu-lgpl-v2

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
AUTO_MKDIRS=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

# remove tex temp files that should not be installed
post-extract:
	rm -f ${WRKSRC}/doc/html/_form*
	rm -f ${WRKSRC}/doc/html/functions_*~.html

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

# Appparently this plugin has a valid expectation that libqwt is
# already loaded, at least as used in qgis.
CHECK_SHLIBS_SKIP+=	qt5/plugins/designer/libqwt_designer_plugin.so
CHECK_SHLIBS_SKIP+=	qt5/plugins/designer/libqwt_designer_plugin.dylib

.include "../../mk/bsd.prefs.mk"

post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool	\
	  -id       ${PREFIX}/qwt-${PKGVERSION_NOREV}/lib/libqwt.${PKGVERSION_NOREV}.dylib	\
	  ${DESTDIR}${PREFIX}/qwt-${PKGVERSION_NOREV}/lib/libqwt.${PKGVERSION_NOREV}.dylib
.endif

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
