# $NetBSD: Makefile,v 1.34 2022/06/30 11:19:01 nia Exp $

DISTNAME=	kitty-0.25.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=kovidgoyal/}
GITHUB_PROJECT=	kitty
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sw.kovidgoyal.net/kitty/index.html
COMMENT=	GPU based terminal emulator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c
EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake pkg-config

# don't force LTO
BUILDLINK_TRANSFORM+=	rm:-flto
# code is not perfect
BUILDLINK_TRANSFORM+=	rm:-Werror
BUILDLINK_TRANSFORM+=	rm:-pedantic-errors

# kitty's homegrown packaging expects the functionality of tic(1) that
# comes with ncurses.
USE_NCURSES=	yes

CHECK_INTERPRETER_SKIP=	lib/kitty/shell-integration/ssh/askpass.py

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=			yes

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py linux-package

do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHONBIN} setup.py linux-package \
	    --prefix ${DESTDIR}${PREFIX}
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/kitty.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/kitty.1 || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/share/man/man5/kitty.conf.5 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/kitty.conf.5 || ${TRUE}
# pkgsrc framwork only handles optimization level 1 files correctly
	${FIND} ${DESTDIR} -type f -name *.opt-2.pyc -print0 | ${XARGS} -0 ${RM} -rf
	${FIND} ${DESTDIR} -name '*.orig' -exec rm -rf '{}' ';'

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
.include "../../net/librsync/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
