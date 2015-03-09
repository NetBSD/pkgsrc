# $NetBSD: Makefile,v 1.3 2015/03/09 16:52:45 imil Exp $

DISTNAME=	0.9.2
EGG_NAME=	httpie-${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	www
MASTER_SITES=	https://github.com/jakubroztocil/httpie/archive/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jakubroztocil/httpie
COMMENT=	Human-friendly command line HTTP client
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/httpie-${DISTNAME}

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-curses>=${PY_DISTVERSION}:../../devel/py-curses

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
