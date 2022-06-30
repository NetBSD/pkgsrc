# $NetBSD: Makefile,v 1.9 2022/06/30 11:18:55 nia Exp $

DISTNAME=	subliminal-2.1.0
PKGREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/subliminal/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/Diaoul/subliminal
COMMENT=	Video subtitles downloader
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.3:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-babelfish>=0.5.2:../../textproc/py-babelfish
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-chardet>=2.3.0:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-click>=4.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dogpile-cache>=0.6.0:../../devel/py-dogpile-cache
DEPENDS+=	${PYPKGPREFIX}-enzyme>=0.4.1:../../multimedia/py-enzyme
DEPENDS+=	${PYPKGPREFIX}-guessit>=3.0.0:../../textproc/py-guessit
DEPENDS+=	${PYPKGPREFIX}-pysrt>=1.0.1:../../textproc/py-pysrt
DEPENDS+=	${PYPKGPREFIX}-pytz>=2012c:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-rarfile>=2.7:../../archivers/py-rarfile
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stevedore>=1.20.0:../../devel/py-stevedore

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-dogpile-cache, py-stevedore

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} subliminal subliminal-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
