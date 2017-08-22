# $NetBSD: Makefile,v 1.4 2017/08/22 07:46:22 adam Exp $

DISTNAME=	natsort-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/natsort/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/SethMMorton/natsort
COMMENT=	Natural sorting for python
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} natsort natsort${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
