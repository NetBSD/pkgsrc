# $NetBSD: Makefile,v 1.4 2012/10/04 00:22:01 cheusov Exp $
#

VERS=		0.2.5
DISTNAME=	python-creole-${VERS}
PKGNAME=	${PYPKGPREFIX}-creole-${VERS}
PKGREVISION=	1
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
