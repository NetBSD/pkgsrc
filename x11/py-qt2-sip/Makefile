# $NetBSD: Makefile,v 1.18 2006/05/21 02:10:53 wiz Exp $
#

DISTNAME=	sip-3.1
PKGNAME=	${PYPKGPREFIX}-qt2-sip-3.1
PKGREVISION=	4
CATEGORIES=	x11 devel python
MASTER_SITES=	http://www.riverbankcomputing.co.uk/download/sip/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/sip/index.php
COMMENT=	Tool to create Python bindings for C++ libraries

USE_LANGUAGES=		c++
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q} \
			--with-qt-dir=${QTDIR:Q}

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
