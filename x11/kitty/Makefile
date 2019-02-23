# $NetBSD: Makefile,v 1.7 2019/02/23 21:50:46 gutteridge Exp $

DISTNAME=	kitty-0.13.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=kovidgoyal/}
GITHUB_PROJECT=	kitty
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sw.kovidgoyal.net/kitty/index.html
COMMENT=	GPU based terminal emulator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c99
EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	app

.include "../../mk/bsd.prefs.mk"

# kitty's homegrown packaging expects the functionality of tic(1) that
# comes with ncurses.
USE_NCURSES=	yes

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Replace path of Python interpreter.
SUBST_FILES.python+=	Makefile
SUBST_FILES.python+=	docs/Makefile
SUBST_SED.python+=	-e "s,python3,python${PYVERSSUFFIX},g"
SUBST_SED.python+=	-e "s,sphinx-build,sphinx-build${PYVERSSUFFIX},g"

# Sample auto-generated files are placed in randomly-named directories at
# generation time, which makes for non-reproducible builds.
SUBST_CLASSES+=		html
SUBST_STAGE.html=	post-install
SUBST_MESSAGE.html=	Replace path of auto-generated config samples.
SUBST_FILES.html+=	${DESTDIR}${PREFIX}/share/doc/kitty/html/conf.html
SUBST_SED.html+=	-e "s,_downloads/[0-9a-f]\{32\}/,_downloads/,g"

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

REPLACE_PYTHON+=	kitty/launcher/kitty

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py linux-package
	cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} man

do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py linux-package \
	    --prefix ${DESTDIR}${PREFIX}
	${INSTALL_DATA} ${WRKSRC}/man/man1/kitty.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/kitty.1

# The other half of dealing with the non-reproducible (or just unneeded)
# build artifacts.
	${FIND} ${DESTDIR}${PREFIX}/share/doc/kitty/html/_downloads \
	    -type f -name *.conf | ${XARGS} -I rep ${MV} rep \
	    ${DESTDIR}${PREFIX}/share/doc/kitty/html/_downloads
	${FIND} ${DESTDIR}${PREFIX}/share/doc/kitty/html/_downloads/* \
	    -type d | ${XARGS} ${RM} -rf
	cd ${DESTDIR}${PREFIX}/share/doc/kitty/html/ && \
	    ${RM} -f .buildinfo .nojekyll objects.inv

.if ${OPSYS} != "Darwin"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
