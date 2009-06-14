# $NetBSD: Makefile,v 1.2 2009/06/14 06:33:44 hasso Exp $

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-tiff-${QTVERSION}
COMMENT=	QT TIFF image format plugin

CONFIGURE_ARGS+=	-I${QTDIR}/include
CONFIGURE_ARGS+=	-L${QTDIR}/lib

BUILD_QT4=		yes

do-build:
	cd ${WRKSRC}/src/tools/bootstrap && env ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/src/tools/moc && env ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/src/plugins/imageformats/tiff && env ${MAKE_ENV} ${GMAKE}

IMGFMTDIR=	${QTPREFIX}/plugins/imageformats

do-install:
	${INSTALL_DATA_DIR} ${IMGFMTDIR}
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/imageformats/libqtiff.la \
		${IMGFMTDIR}

# up to 4.3.2 a builtin libtiff is used
BUILDLINK_API_DEPENDS.qt4-libs+= qt4-libs>=4.3.2nb1
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
