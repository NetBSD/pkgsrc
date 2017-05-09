# $NetBSD: Makefile,v 1.3 2017/05/09 11:54:07 adam Exp $

DISTNAME=	natsort-5.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/natsort/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/SethMMorton/natsort
COMMENT=	Natural sorting for python
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/natsort \
		${DESTDIR}${PREFIX}/bin/natsort${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
