# $NetBSD: Makefile,v 1.3 2012/10/03 23:40:39 cheusov Exp $
#

VERS=		0.2.5
DISTNAME=	python-creole-${VERS}
PKGNAME=	${PYPKGPREFIX}-creole-${VERS}
EGG_NAME=	python_creole-${VERS}
CATEGORIES=	textproc www python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-creole/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://code.google.com/p/python-creole/
COMMENT=	Creole <-> HTML converter

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
