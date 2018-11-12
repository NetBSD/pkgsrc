# $NetBSD: Makefile,v 1.40 2018/11/12 03:53:12 ryoon Exp $

DISTNAME=	PyQt5_gpl-5.11.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt5_gpl/qt5/}
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyqt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding for Qt5
HOMEPAGE=	http://www.riverbankcomputing.com/software/pyqt/intro

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-q ${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	--confirm-license
CONFIGURE_ARGS+=	--qsci-api
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
SUBST_SED.x11lib+=	-e 's,@PREFIX@,${PREFIX},'

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

.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-sip+=	${PYPKGPREFIX}-sip>=4.19.4
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtcharts/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtnetworkauth/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
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
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
