# $NetBSD: Makefile,v 1.6 2018/11/21 17:18:04 adam Exp $

DISTNAME=	httpie-1.0.0
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpie/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jakubroztocil/httpie
COMMENT=	Human-friendly command line HTTP client
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-curses>=${PY_DISTVERSION}:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.1.3:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.4:../../devel/py-requests

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} http http-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
