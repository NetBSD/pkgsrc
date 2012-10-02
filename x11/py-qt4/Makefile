# $NetBSD: Makefile,v 1.54 2012/10/02 17:12:18 tron Exp $

PKGNAME=	${PYPKGPREFIX}-qt4-${PYQT_VERSION}
PYQT_VERSION=	4.9.4
PKGREVISION=	3
CATEGORIES=	x11 python
MASTER_SITES=	http://www.riverbankcomputing.com/static/Downloads/PyQt4/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding for Qt4
HOMEPAGE=	http://www.riverbankcomputing.com/software/pyqt/intro

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-v ${PREFIX}/share/sip${PYVERSSUFFIX}
CONFIGURE_ARGS+=	-q ${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	--confirm-license
CONFIGURE_ARGS+=	--qsci-api

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PYTHON_VERSIONS_INCOMPATIBLE=	25
PYTHON_VERSIONS_INCLUDE_3X=	yes

BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtCore
BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtDeclarative
BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtDesigner
BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtGui
BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtOpenGL
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtCore
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtDeclarative
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtDesigner
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtGui
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtOpenGL

# This is a hack. CPPFLAGS and CXXFLAGS from the environment are ignored,
# however, so I don't know a better way to fix it.
SUBST_CLASSES+=		PIC
SUBST_STAGE.PIC=	post-configure
SUBST_FILES.PIC=	qpy/QtCore/Makefile qpy/QtGui/Makefile
SUBST_SED.PIC=		-e "s/CXXFLAGS      =/CXXFLAGS      = -fPIC/"
SUBST_MESSAGE.PIC=	Adding -fPIC to CXXFLAGS.

#SUBST_CLASSES+=	pyversfx
#SUBST_STAGE.pyversfx=	pre-configure
#SUBST_FILES.pyversfx=	pyuic4/pyuic.sbf pylupdate4/pylupdate.sbf
#SUBST_SED.pyversfx=	-e "s|@PYVERSSUFFIX@|${PYVERSSUFFIX}|g"

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=		${PKGDIR}/PLIST.common
.if ${OPSYS} == "Darwin"
# XXX this is not recorded in distinfo
DISTNAME=		PyQt-mac-gpl-${PYQT_VERSION}
.else
DISTNAME=		PyQt-x11-gpl-${PYQT_VERSION}
PLIST_SRC+=		${PKGDIR}/PLIST.X11
.endif
.include "../../lang/python/extension.mk"

CONFIGURE_ARGS+=	--verbose
do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS})

.include "../../x11/py-sip/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
# needs the QtXmlPatterns fix
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.6.1nb3
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.4.0nb1
BUILDLINK_DEPMETHOD.qt4-tools=		full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
