# $NetBSD: Makefile,v 1.39 2022/06/28 11:37:57 wiz Exp $

PKGNAME=	qt4-mng-${QTVERSION}
PKGREVISION=	8
COMMENT=	QT MNG image format plugin

.include "../../x11/qt4-libs/Makefile.common"
CONFIGURE_ARGS+=	-I${QTDIR}/include
CONFIGURE_ARGS+=	-L${QTDIR}/lib

TOOLS_BROKEN+=	perl

BUILD_QT4=		yes

do-build:
	cd ${WRKSRC}/src/tools/bootstrap && env ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/src/tools/moc && env ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/src/plugins/imageformats/mng && env ${MAKE_ENV} ${GMAKE}

IMGFMTDIR=	${QTPREFIX}/plugins/imageformats

INSTALLATION_DIRS=	${IMGFMTDIR}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/imageformats/libqmng.la ${DESTDIR}${IMGFMTDIR}

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
