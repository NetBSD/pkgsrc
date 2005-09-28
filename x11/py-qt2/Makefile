# $NetBSD: Makefile,v 1.14 2005/09/28 20:52:28 rillig Exp $
#

DISTNAME=	PyQt-3.1-Qt-2.3.1
PKGNAME=	${PYPKGPREFIX}-qt2-3.1
PKGREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	http://www.riverbankcomputing.co.uk/download/PyQt/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/pyqt/index.php
COMMENT=	Python bindings for the Qt toolkit

WRKSRC=			${WRKDIR}/PyQt-3.1
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-python=${PYTHONBIN} \
			--with-qt-dir=${QTDIR}

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/py-qt2-sip/buildlink3.mk"
.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
