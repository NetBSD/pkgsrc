# $NetBSD: Makefile,v 1.20 2010/02/25 17:03:13 wiz Exp $
#

PKGNAME=		${PYPKGPREFIX}-qt4-${PYQT_VERSION}
PYQT_VERSION=		4.7
PKGREVISION=		1
CATEGORIES=		x11 python
MASTER_SITES=		http://www.riverbankcomputing.com/static/Downloads/PyQt4/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Python binding for Qt4
HOMEPAGE=		http://www.riverbankcomputing.com/software/pyqt/intro

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-v ${PREFIX}/share/sip${PYVERSSUFFIX}
CONFIGURE_ARGS+=	-q ${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	--confirm-license

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR:Q}

PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

# This is a hack. CPPFLAGS and CXXFLAGS from the environment are ignored,
# however, so I don't know a better way to fix it.
SUBST_CLASSES+=			PIC
SUBST_STAGE.PIC=		post-configure
SUBST_FILES.PIC=		qpy/QtCore/Makefile qpy/QtGui/Makefile
SUBST_SED.PIC=			-e "s/CXXFLAGS      =/CXXFLAGS      = -fPIC/"
SUBST_MESSAGE.PIC=		Adding -fPIC to CXXFLAGS.

#SUBST_CLASSES+=		pyversfx
#SUBST_STAGE.pyversfx=	pre-configure
#SUBST_FILES.pyversfx=	pyuic4/pyuic.sbf pylupdate4/pylupdate.sbf
#SUBST_SED.pyversfx=	-e "s|@PYVERSSUFFIX@|${PYVERSSUFFIX}|g"

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=		${PKGDIR}/PLIST.common
.if ${OPSYS} == "Darwin"
DISTNAME=		PyQt-mac-gpl-${PYQT_VERSION}
PLIST_SRC+=		${PKGDIR}/PLIST.Darwin
.else
DISTNAME=		PyQt-x11-gpl-${PYQT_VERSION}
PLIST_SRC+=		${PKGDIR}/PLIST.X11
.endif
.include "../../lang/python/extension.mk"
.if ${PYPKGPREFIX} == "py24"
PLIST_SRC+=		${PKGDIR}/PLIST.elementtree
.endif

PYCFILES=		port_v2/__init__.pyc
PYCFILES+=		port_v2/ascii_upper.pyc
PYCFILES+=		port_v2/encode_utf8.pyc
PYCFILES+=		port_v2/invoke.pyc
PYCFILES+=		port_v2/load_plugin.pyc
PYCFILES+=		port_v2/proxy_base.pyc
PYCFILES+=		port_v2/string_io.pyc
PYCFILES+=		Loader/__init__.pyc
PYCFILES+=		Loader/loader.pyc
PYCFILES+=		Loader/qobjectcreator.pyc
PYCFILES+=		widget-plugins/phonon.pyc
PYCFILES+=		widget-plugins/qaxcontainer.pyc
PYCFILES+=		widget-plugins/qscintilla.pyc
PYCFILES+=		widget-plugins/qtwebkit.pyc
PYCFILES+=		Compiler/__init__.pyc
PYCFILES+=		Compiler/compiler.pyc
PYCFILES+=		Compiler/indenter.pyc
PYCFILES+=		Compiler/misc.pyc
PYCFILES+=		Compiler/proxy_type.pyc
PYCFILES+=		Compiler/qobjectcreator.pyc
PYCFILES+=		Compiler/qtproxies.pyc
PYCFILES+=		port_v3/__init__.pyc
PYCFILES+=		port_v3/ascii_upper.pyc
PYCFILES+=		port_v3/encode_utf8.pyc
PYCFILES+=		port_v3/invoke.pyc
PYCFILES+=		port_v3/load_plugin.pyc
PYCFILES+=		port_v3/proxy_base.pyc
PYCFILES+=		port_v3/string_io.pyc
PYCFILES+=		__init__.pyc
PYCFILES+=		driver.pyc
PYCFILES+=		exceptions.pyc
PYCFILES+=		icon_cache.pyc
PYCFILES+=		objcreator.pyc
PYCFILES+=		properties.pyc
PYCFILES+=		pyuic.pyc
PYCFILES+=		uiparser.pyc

CONFIGURE_ARGS+=	--verbose
do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS})

post-build:
	cd ${WRKSRC}/pyuic/uic && ${PY_COMPILE_ALL} .
	cd ${WRKSRC} && ${PYTHONBIN} ${PREFIX}/lib/python${PYVERSSUFFIX}/py_compile.py  __init__.py
	cd ${WRKSRC} && ${PYTHONBIN} ${PREFIX}/lib/python${PYVERSSUFFIX}/py_compile.py pyqtconfig.py

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt4/uic/port_v3/proxy_base.py.orig
	for file in ${PYCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/pyuic/uic/$$file \
			${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt4/uic/$$file; \
	done
	${INSTALL_DATA} ${WRKSRC}/__init__.pyc \
		${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt4
	${INSTALL_DATA} ${WRKSRC}/pyqtconfig.pyc \
		${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt4

.include "../../x11/py-sip/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
# needs the QtXmlPatterns fix
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.6.1nb3
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.4.0nb1
.include "../../x11/qt4-tools/buildlink3.mk"
# ${PYSITELIB}/qt.so depends on libqassistantclient.so
#  which is part of qt4-tools, so we need a runtime dependency
#  XXX split this pkg?
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../mk/bsd.pkg.mk"
