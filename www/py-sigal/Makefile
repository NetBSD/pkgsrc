# $NetBSD: Makefile,v 1.6 2023/10/28 19:57:25 wiz Exp $

DISTNAME=	sigal-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sigal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/sigal/
COMMENT=	Simple static gallery generator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	ffmpeg6-[0-9]*:../../multimedia/ffmpeg6
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-feedgenerator-[0-9]*:../../www/py-feedgenerator
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-natsort-[0-9]*:../../textproc/py-natsort
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-pilkit-[0-9]*:../../graphics/py-pilkit
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

SUBST_CLASSES+=		ffmpeg
SUBST_SED.ffmpeg+=	-e "s,ffmpeg,${PREFIX}/bin/ffmpeg6,"
SUBST_FILES.ffmpeg+=	src/sigal/settings.py
SUBST_FILES.ffmpeg+=	src/sigal/video.py
SUBST_STAGE.ffmpeg=	pre-build
SUBST_MESSAGE.ffmpeg=	Fixing ffmpeg path.

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv sigal sigal-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
