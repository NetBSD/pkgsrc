# $NetBSD: Makefile,v 1.13 2024/05/29 16:35:09 adam Exp $

DISTNAME=	PyQt6-6.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt6/qt6/}
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding for Qt6
HOMEPAGE=	https://www.riverbankcomputing.com/software/pyqt/
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder>=1.15:../../x11/py-qt-builder
TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6>=6.8:../../x11/py-sip6
# Binaries won't work without this:
DEPENDS+=	${PYPKGPREFIX}-sip-qt6-[0-9]*:../../x11/py-sip-qt6

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

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
.endif

post-install:
.for bin in pylupdate6 pyuic6
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../audio/qt6-qtspeech/buildlink3.mk"
.include "../../comms/qt6-qtconnectivity/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/qt6-qtcharts/buildlink3.mk"
.include "../../graphics/qt6-qtquick3d/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../geography/qt6-qtlocation/buildlink3.mk"
.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../misc/qt6-qtsensors/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../net/qt6-qtremoteobjects/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../www/qt6-qtwebchannel/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/qt6-qtserialport/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
