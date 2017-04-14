# $NetBSD: Makefile,v 1.2 2017/04/14 19:10:23 leot Exp $

DISTNAME=	subliminal-2.0.5
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=s/subliminal/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/Diaoul/subliminal/
COMMENT=	Video subtitles downloader
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.3:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-babelfish>=0.5.2:../../textproc/py-babelfish
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-chardet>=2.3.0:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-click>=4.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dogpile-cache>=0.6.0:../../devel/py-dogpile-cache
DEPENDS+=	${PYPKGPREFIX}-enzyme>=0.4.1:../../multimedia/py-enzyme
DEPENDS+=	${PYPKGPREFIX}-guessit>=2.0.1:../../textproc/py-guessit
DEPENDS+=	${PYPKGPREFIX}-pysrt>=1.0.1:../../textproc/py-pysrt
DEPENDS+=	${PYPKGPREFIX}-pytz>=2012c:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-rarfile>=2.7:../../archivers/py-rarfile
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stevedore>=1.0.0:../../devel/py-stevedore

.include "../../lang/python/egg.mk"

.if ${_PYTHON_VERSION} < 33
DEPENDS+=	${PYPKGPREFIX}-futures>=3.0:../../devel/py-futures
.endif

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/subliminal ${DESTDIR}${PREFIX}/bin/subliminal-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
