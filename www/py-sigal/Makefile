# $NetBSD: Makefile,v 1.9 2025/02/26 09:39:03 adam Exp $

DISTNAME=	sigal-2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sigal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saimn/sigal
COMMENT=	Simple static gallery generator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
DEPENDS+=	ffmpeg7-[0-9]*:../../multimedia/ffmpeg7
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-natsort-[0-9]*:../../textproc/py-natsort
DEPENDS+=	${PYPKGPREFIX}-pilkit-[0-9]*:../../graphics/py-pilkit
# optional
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-feedgenerator-[0-9]*:../../www/py-feedgenerator
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

SUBST_CLASSES+=		ffmpeg
SUBST_SED.ffmpeg+=	-e "s,ffmpeg,${PREFIX}/bin/ffmpeg7,"
SUBST_FILES.ffmpeg+=	src/sigal/settings.py
SUBST_FILES.ffmpeg+=	src/sigal/video.py
SUBST_STAGE.ffmpeg=	pre-build
SUBST_MESSAGE.ffmpeg=	Fixing ffmpeg path.

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv sigal sigal-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
