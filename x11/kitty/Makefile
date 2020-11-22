# $NetBSD: Makefile,v 1.21 2020/11/22 14:24:22 pin Exp $

DISTNAME=	kitty-0.19.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=kovidgoyal/}
GITHUB_PROJECT=	kitty
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sw.kovidgoyal.net/kitty/index.html
COMMENT=	GPU based terminal emulator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c99
EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake pkg-config

# don't force LTO
BUILDLINK_TRANSFORM+=	rm:-flto

# kitty's homegrown packaging expects the functionality of tic(1) that
# comes with ncurses.
USE_NCURSES=	yes

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools:tool

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Replacing path to Sphinx.
SUBST_FILES.python=	docs/Makefile
SUBST_SED.python+=	-e "s,sphinx-build,sphinx-build-${PYVERSSUFFIX},g"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONED_DEPENDENCIES+=	sphinx:tool

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py linux-package
	cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} man

do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py linux-package \
	    --prefix ${DESTDIR}${PREFIX}
	${FIND} ${DESTDIR} -type d -name __pycache__ -print0 | ${XARGS} -0 ${RM} -rf
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/kitty.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/kitty.1 || ${FALSE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
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
.include "../../lang/python/tool.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
