# $NetBSD: Makefile,v 1.5 2018/05/02 07:29:16 adam Exp $

DISTNAME=	httpie-0.9.9
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpie/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jakubroztocil/httpie
COMMENT=	Human-friendly command line HTTP client
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-curses>=${PY_DISTVERSION}:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.1.3:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.11.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
