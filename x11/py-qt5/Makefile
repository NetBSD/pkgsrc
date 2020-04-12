# $NetBSD: Makefile,v 1.56 2020/04/12 06:24:30 adam Exp $

DISTNAME=	PyQt5-5.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt5/qt5/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt5/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding for Qt5
HOMEPAGE=	https://www.riverbankcomputing.com/software/pyqt/intro
LICENSE=	gnu-gpl-v3 

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif
DEPENDS+=	${PYPKGPREFIX}-sip-qt5-[0-9]*:../../x11/py-sip-qt5

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	--sipdir ${PREFIX}/share/sip${PYVERSSUFFIX}/PyQt5
CONFIGURE_ARGS+=	--qml-plugindir ${PREFIX}/qt5/plugins/PyQt5-${PYVERSSUFFIX}/
CONFIGURE_ARGS+=	--designer-plugindir ${PREFIX}/qt5/plugins/designer${PYVERSSUFFIX}/
CONFIGURE_ARGS+=	-q ${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	--confirm-license
CONFIGURE_ARGS+=	--qsci-api
CONFIGURE_ARGS+=	--qsci-api-destdir ${PREFIX}/qt5/qsci${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--sip ${BUILDLINK_PREFIX.py-sip}/bin/sip${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--verbose

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

PLIST_VARS+=		webkit x11
PY_PATCHPLIST=		yes

SUBST_CLASSES+=		x11lib
SUBST_STAGE.x11lib=	pre-configure
SUBST_MESSAGE.x11lib=	Fixing rpath for X11 and pulseaudio libraries.
SUBST_FILES.x11lib+=	configure.py
SUBST_FILES.x11lib+=	designer/designer.pro-in
SUBST_FILES.x11lib+=	qmlscene/qmlscene.pro-in
SUBST_SED.x11lib+=	-e 's,@X11LIB@,${X11BASE}/lib,'
SUBST_VARS.x11lib=	PREFIX PYVERSSUFFIX

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	${FIND} ${DESTDIR}${PREFIX} -name '*.so' -or -name '*.dylib' |	\
		while read lib; do					\
		libname=`basename $${lib}`;				\
		libdir=`dirname $${lib} | sed -e 's,${DESTDIR},,'`;	\
		install_name_tool -id $${libdir}/$${libname} $${lib};	\
	done
.else
PLIST.x11=	yes
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pylupdate5 pylupdate5-${PYVERSSUFFIX} && \
	${MV} pyrcc5 pyrcc5-${PYVERSSUFFIX} && \
	${MV} pyuic5 pyuic5-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-sip+=	${PYPKGPREFIX}-sip>=4.19.14
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtcharts/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtnetworkauth/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.if ${OPSYS} == "Darwin"
.  include "../../x11/qt5-qtmacextras/buildlink3.mk"
.else
# currently qt5-qtwebkit does not build on Darwin
PLIST.webkit=	yes
.  include "../../x11/qt5-qtwebkit/buildlink3.mk"
.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
