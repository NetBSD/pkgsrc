# $NetBSD: Makefile,v 1.1.1.1 2008/12/13 05:19:12 epg Exp $
#

PKGNAME=		${PYPKGPREFIX}-qt4-${PYQT_VERSION}
PYQT_VERSION=		4.4.4
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
# XXX: should not be necessary, but framework thinks pkgsrc only has static
# qt4 libraries
#epg fixed? with patch-aa
#CONFIGURE_ARGS+=	-k
CONFIGURE_ARGS+=	--confirm-license

PYTHON_VERSIONS_ACCEPTED=	25 24 23
PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

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
PLIST_SRC+=		${PKGDIR}/PLIST.common_end

CONFIGURE_ARGS+=	--verbose
do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS})

.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.py-sip+=	${PYPKGPREFIX}-sip>=4.7.9
.include "../../x11/py-sip/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.4.0nb1
.include "../../x11/qt4-tools/buildlink3.mk"
# ${PYSITELIB}/qt.so depends on libqassistantclient.so
#  which is part of qt4-tools, so we need a runtime dependency
#  XXX split this pkg?
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../mk/bsd.pkg.mk"
