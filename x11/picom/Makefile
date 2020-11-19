# $NetBSD: Makefile,v 1.5 2020/11/19 11:03:04 nia Exp $

DISTNAME=	picom-8.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=yshui/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yshui/picom
COMMENT=	Lightweight compositor for X11 (fork of Compton)
LICENSE=	mpl-2.0 AND mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFLICTS+=	compton-[0-9]*
SUPERSEDES+=	compton-[0-9]*

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

MESON_ARGS+=	-Dwith_docs=true

REPLACE_SH+=		bin/picom-trans

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man ${DESTDIR}${PREFIX}/${PKGMANDIR} || ${TRUE}

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
