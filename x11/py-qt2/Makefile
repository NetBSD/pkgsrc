# $NetBSD: Makefile,v 1.4 2004/01/20 12:28:27 agc Exp $
#

DISTNAME=	PyQt-3.1-Qt-2.3.1
PKGNAME=	${PYPKGPREFIX}-qt2-3.1
CATEGORIES=	x11
MASTER_SITES=	http://www.riverbankcomputing.co.uk/download/PyQt/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/pyqt/index.php
COMMENT=	Python bindings for the Qt tooltit

WRKSRC=			${WRKDIR}/PyQt-3.1
USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

HAVE_CONFIGURE=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--with-python=${PYTHONBIN} \
			--with-qt-dir=${QTDIR}

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"

.include "../../x11/py-qt2-sip/buildlink2.mk"
.include "../../x11/qt2-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
