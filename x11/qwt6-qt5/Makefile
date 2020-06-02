# $NetBSD: Makefile,v 1.8 2020/06/02 08:23:07 adam Exp $

DISTNAME=	qwt-6.1.4
PKGNAME=	qwt6-qt5-6.1.4
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qwt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/qwt/
COMMENT=	Qt widget library for technical purposes
LICENSE=	gnu-lgpl-v2

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

AUTO_MKDIRS=		yes
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

PLIST_SUBST+=	VERSION=${PKGVERSION_NOREV}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

# Appparently this plugin has a valid expectation that libqwt is
# already loaded, at least as used in qgis.
CHECK_SHLIBS_SKIP+=	qt5/plugins/designer/libqwt_designer_plugin.so

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
