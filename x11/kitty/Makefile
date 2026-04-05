# $NetBSD: Makefile,v 1.83.2.1 2026/04/05 16:12:32 maya Exp $

DISTNAME=	kitty-0.46.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=kovidgoyal/}
GITHUB_PROJECT=	kitty
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sw.kovidgoyal.net/kitty/index.html
COMMENT=	GPU based terminal emulator
LICENSE=	gnu-gpl-v3

GO_VERSION_REQD+=	126

USE_LANGUAGES=	c
USE_TOOLS+=	gmake pkg-config

USE_CXX_FEATURES+=	has_include

TOOL_DEPENDS+=	nerd-fonts-NerdFontsSymbolsOnly-[0-9]*:../../fonts/nerd-fonts-NerdFontsSymbolsOnly

# go
MKPIE_SUPPORTED=	no
CHECK_RELRO_SKIP+=	bin/kitten
CHECK_WRKREF_SKIP+=	bin/kitten

# don't force LTO
BUILDLINK_TRANSFORM+=	rm:-flto
# code is not perfect
BUILDLINK_TRANSFORM+=	rm:-Werror
BUILDLINK_TRANSFORM+=	rm:-pedantic-errors

# kitty's homegrown packaging expects the functionality of tic(1) that
# comes with ncurses.
USE_NCURSES=	yes

CHECK_INTERPRETER_SKIP=	lib/kitty/shell-integration/ssh/askpass.py


PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=			yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=		pre-configure
SUBST_MESSAGE.prefix=	Point to pkgsrc fonts always
SUBST_FILES.prefix+=	setup.py
SUBST_VARS.prefix+=		PREFIX


.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.if ${OPSYS} == "Darwin"
INSTALLATION_DIRS+=	${PREFIX}/share/doc/kitty/html
INSTALLATION_DIRS+=	${PREFIX}/share/icons/hicolor/256x256/apps
INSTALLATION_DIRS+=	${PREFIX}/share/icons/hicolor/scalable/apps
.endif


PLIST_VARS+=		x11

# regardless if you build for wayland, kitty will still build the x11
# stuff. kitty will never build x11 stuff on darwin.
.if ${OPSYS} != "Darwin"
PLIST.x11=	yes
.endif

pre-configure:
	cd ${BUILDLINK_DIR}/bin && ${LN} -s ${PREFIX}/bin/go126 go

do-build:
.if ${OPSYS} == "Darwin"
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py kitty.app
.else
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py linux-package
.endif

do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py linux-package \
	    --prefix ${DESTDIR}${PREFIX}
.if ${OPSYS} == "Darwin"
	${MV} ${WRKSRC}/docs/_build/man/*.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ || ${TRUE}
	${MV} ${WRKSRC}/docs/_build/man/*.5 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/ || ${TRUE}
	${MV} ${WRKSRC}/docs/_build/html \
	    ${DESTDIR}${PREFIX}/share/doc/kitty/ || ${TRUE}
	${INSTALL_PROGRAM} \
	    ${WRKSRC}/kitty.app/Contents/Resources/kitty/kitty/launcher/kitty \
	    ${DESTDIR}${PREFIX}/lib/kitty/kitty/launcher/
	${MV} ${WRKSRC}/logo/kitty.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/ || ${TRUE}
	${MV} ${WRKSRC}/logo/kitty.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/256x256/apps/ || ${TRUE}
# we don't want to override existing fonts
	${RM} -rf ${DESTDIR}${PREFIX}/share/fonts
.else
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/share/man/man5/* \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/ || ${TRUE}
.endif
# pkgsrc framwork only handles optimization level 1 files correctly
	${FIND} ${DESTDIR} -type f -name *.opt-2.pyc -print0 | ${XARGS} -0 ${RM} -rf
	${FIND} ${DESTDIR} -name '*.orig' -exec rm -rf '{}' ';'


.include "go-modules.mk"

.if ${OPSYS} != "Darwin"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/simde/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
