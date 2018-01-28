# $NetBSD: Makefile,v 1.30 2018/01/28 20:11:09 wiz Exp $

DISTNAME=	PyQt5_gpl-${PYQT_VERSION}
PKGNAME=	${PYPKGPREFIX}-qt5-${PYQT_VERSION}
PKGREVISION=	1
PYQT_VERSION=	5.9.1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyqt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding for Qt5
HOMEPAGE=	http://www.riverbankcomputing.com/software/pyqt/intro

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-q ${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	--confirm-license
CONFIGURE_ARGS+=	--qsci-api
CONFIGURE_ARGS+=	--sip ${BUILDLINK_PREFIX.py-sip}/bin/sip${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--verbose
#MAKEFLAGS+=		LFLAGS=${LDFLAGS:Q}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

PY_PATCHPLIST=		yes

SUBST_CLASSES+=		x11lib

SUBST_STAGE.x11lib=     post-patch
SUBST_SED.x11lib+=      -e 's,@X11LIB@,${X11BASE}/lib,'
SUBST_SED.x11lib+=      -e 's,@PREFIX@,${PREFIX},'
SUBST_MESSAGE.x11lib=   Fixing rpath for X11 and pulseaudio libraries.
SUBST_FILES.x11lib+=    configure.py
SUBST_FILES.x11lib+=    designer/designer.pro-in
SUBST_FILES.x11lib+=    qmlscene/qmlscene.pro-in

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS}

.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-sip+=	${PYPKGPREFIX}-sip>=4.19.4
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
