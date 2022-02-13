# $NetBSD: Makefile,v 1.5 2022/02/13 09:27:13 adam Exp $

DISTNAME=	epr-reader-2.4.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/epr-reader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wustho/epr
COMMENT=	Terminal/CLI Epub Reader
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-curses>0:../../devel/py-curses

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} epr epr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
