# $NetBSD: Makefile,v 1.1.1.1 2002/04/17 10:31:36 drochner Exp $
#

DISTNAME=	PyQt-3.1-Qt-2.3.1
PKGNAME=	${PYPKGPREFIX}-qt2-3.1
WRKSRC=		${WRKDIR}/PyQt-3.1
CATEGORIES=	x11
MASTER_SITES=	http://www.riverbankcomputing.co.uk/download/PyQt/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/pyqt/index.php
COMMENT=	Python bindings for the Qt tooltit

USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK_ONLY=	yes

HAVE_CONFIGURE=	YES
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-python=${PYTHONBIN} \
		--with-qt-dir=${QT_BUILDLINK_DIR}

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../x11/py-qt2-sip/buildlink.mk"
.include "../../lang/python/extension.buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
