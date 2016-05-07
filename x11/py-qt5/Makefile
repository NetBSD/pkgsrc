# $NetBSD: Makefile,v 1.9.2.1 2016/05/07 19:02:17 bsiegert Exp $

DISTNAME=	PyQt-gpl-${PYQT_VERSION}
PKGNAME=	${PYPKGPREFIX}-qt5-${PYQT_VERSION}
PKGREVISION=	4
PYQT_VERSION=	5.5.1
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

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

SUBST_CLASSES+=		install x11lib
SUBST_STAGE.install=	post-configure
SUBST_SED.install+=	-e 's,INSTALL_FILE  = ,INSTALL_FILE  = libtool --mode=install ,'
SUBST_SED.install+=	-e 's,\(TARGET[A-Z ]*\)= lib,\1= ,'
SUBST_MESSAGE.install=	Fixing installation target and file name.
SUBST_FILES.install+=	Qt/Makefile
SUBST_FILES.install+=	QtCore/Makefile
SUBST_FILES.install+=	QtDBus/Makefile
SUBST_FILES.install+=	QtDesigner/Makefile
SUBST_FILES.install+=	QtGui/Makefile
SUBST_FILES.install+=	QtHelp/Makefile
SUBST_FILES.install+=	QtMultimedia/Makefile
SUBST_FILES.install+=	QtMultimediaWidgets/Makefile
SUBST_FILES.install+=	QtNetwork/Makefile
SUBST_FILES.install+=	QtOpenGL/Makefile
SUBST_FILES.install+=	QtPositioning/Makefile
SUBST_FILES.install+=	QtPrintSupport/Makefile
SUBST_FILES.install+=	QtQml/Makefile
SUBST_FILES.install+=	QtQuick/Makefile
SUBST_FILES.install+=	QtSensors/Makefile
SUBST_FILES.install+=	QtSql/Makefile
SUBST_FILES.install+=	QtSvg/Makefile
SUBST_FILES.install+=	QtTest/Makefile
SUBST_FILES.install+=	QtWebKit/Makefile
SUBST_FILES.install+=	QtWebKitWidgets/Makefile
SUBST_FILES.install+=	QtWidgets/Makefile
SUBST_FILES.install+=	QtXmlPatterns/Makefile
SUBST_FILES.install+=	_QOpenGLFunctions_2_0/Makefile

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
BUILDLINK_API_DEPENDS.py-sip+=	${PYPKGPREFIX}-sip>=4.16.4
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
