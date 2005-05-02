# $NetBSD: Makefile,v 1.15 2005/05/02 15:36:53 drochner Exp $
#

DISTNAME=		PyQt-x11-gpl-3.14.1
PKGNAME=		${PYPKGPREFIX}-qt3-modules-3.14.1
CATEGORIES=		x11 python
MASTER_SITES=		http://www.river-bank.demon.co.uk/download/PyQt/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.riverbankcomputing.co.uk/pyqt/
COMMENT=		Python binding for qt3

USE_X11=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

CONFIGURE_ARGS=		-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-v ${PREFIX}/share/sip${PYVERSSUFFIX}

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

INSTALL_DIRS=	${WRKSRC}/qtcanvas ${WRKSRC}/qtgl ${WRKSRC}/qtnetwork
INSTALL_DIRS+=	${WRKSRC}/qtsql ${WRKSRC}/qttable ${WRKSRC}/qtui
INSTALL_DIRS+=	${WRKSRC}/qtxml

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS})

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
