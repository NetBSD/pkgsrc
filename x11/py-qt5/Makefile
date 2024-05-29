# $NetBSD: Makefile,v 1.93 2024/05/29 16:35:09 adam Exp $

DISTNAME=	PyQt5-5.15.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt5/qt5/}
PKGREVISION=	7
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt5/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding for Qt5
HOMEPAGE=	https://www.riverbankcomputing.com/software/pyqt/intro
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder
DEPENDS+=	${PYPKGPREFIX}-sip-qt5>=12:../../x11/py-sip-qt5

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

PLIST_VARS+=		x11

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		x11lib
SUBST_STAGE.x11lib=	pre-configure
SUBST_MESSAGE.x11lib=	Fixing rpath for X11 and pulseaudio libraries.
SUBST_FILES.x11lib+=	designer/designer.pro-in
SUBST_FILES.x11lib+=	qmlscene/qmlscene.pro-in
SUBST_SED.x11lib+=	-e 's,@X11LIB@,${X11BASE}/lib,'

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

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
.for bin in pylupdate5 pyrcc5 pyuic5
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtcharts/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.if ${OPSYS} == "Darwin"
.  include "../../x11/qt5-qtmacextras/buildlink3.mk"
.else
.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
