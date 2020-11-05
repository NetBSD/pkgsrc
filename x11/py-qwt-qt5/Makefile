# $NetBSD: Makefile,v 1.2 2020/11/05 09:09:26 ryoon Exp $

VERSION=	1.02.00
DISTNAME=	pyqt-qwt-${VERSION}
PKGNAME=	${PYPKGPREFIX}-qwt-qt5-${DISTNAME:S/pyqt-qwt-//}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=GauiStori/}
GITHUB_PROJECT=	PyQt-Qwt
GITHUB_TAG=	pyqt-qwt-${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GauiStori/PyQt-Qwt/
COMMENT=	Python PyQt wrapper for Qwt6
#LICENSE=	# gnu-lgpl-v2.1 with exception (Qwt License)

BUILD_DEPENDS+=	qt5-qtbase-[0-9]*:../../x11/qt5-qtbase

WRKSRC=		${WRKDIR}/PyQt-Qwt-pyqt-qwt-${VERSION}

CONFIGURE_ENV+=	QT_SELECT=qt5
MAKE_ENV+=	PATH=${PATH}:${PREFIX}/qt5/bin
INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR}
ALL_ENV+=	LFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/${BUILDLINK_LIBDIRS.qwt6-qt5}
USE_LANGUAGES=	c++

PY_PATCHPLIST=	yes

do-configure:
	set -e; cd ${WRKSRC};						\
	  ${PKGSRC_SETENV} ${CONFIGURE_ENV}				\
	  ${PYTHONBIN} configure.py					\
	  --qwt-incdir=${PREFIX}/${BUILDLINK_INCDIRS.qwt6-qt5}		\
	  --qwt-libdir=${PREFIX}/${BUILDLINK_LIBDIRS.qwt6-qt5}		\
	  --qwt-lib=qwt							\
	  --sip=${PREFIX}/bin/sip${PYVERSSUFFIX}			\
	  --qmake=${PREFIX}/qt5/bin/qmake				\
	  --pyqt-sipdir=${PREFIX}/share/sip${PYVERSSUFFIX}/PyQt5	\
	  --verbose

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qwt6-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
