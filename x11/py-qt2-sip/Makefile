# $NetBSD: Makefile,v 1.8 2004/07/22 09:15:59 recht Exp $
#

DISTNAME=	sip-3.1
PKGNAME=	${PYPKGPREFIX}-qt2-sip-3.1
CATEGORIES=	x11 devel python
MASTER_SITES=	http://www.riverbankcomputing.co.uk/download/sip/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/sip/index.php
COMMENT=	Tool to create Python bindings for C++ libraries

USE_BUILDLINK3= 	yes
USE_X11=		# defined
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--with-python=${PYTHONBIN} \
			--with-qt-dir=${QTDIR}

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
