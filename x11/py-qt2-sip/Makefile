# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:56 jlam Exp $
#

DISTNAME=	sip-3.1
PKGNAME=	${PYPKGPREFIX}-qt2-sip-3.1
CATEGORIES=	x11 devel
MASTER_SITES=	http://www.riverbankcomputing.co.uk/download/sip/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/sip/index.php
COMMENT=	Tool to create Python bindings for C++ libraries

USE_BUILDLINK2= 	# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--with-python=${PYTHONBIN} \
			--with-qt-dir=${QTDIR}

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../x11/qt2-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
