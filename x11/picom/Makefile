# $NetBSD: Makefile,v 1.18 2026/10/02 16:11:16 pin Exp $

DISTNAME=	picom-13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=yshui/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yshui/picom
COMMENT=	Lightweight compositor for X11 (fork of Compton)
LICENSE=	mpl-2.0 AND mit

CONFLICTS+=	compton-[0-9]*
SUPERSEDES+=	compton-[0-9]*

.include "../../lang/ruby/rubyversion.mk"

TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor

SUBST_CLASSES+=		rubyver
SUBST_SED.rubyver+=	-e "s/asciidoctor/asciidoctor${RUBY_SUFFIX}/"
SUBST_FILES.rubyver+=	man/meson.build
SUBST_STAGE.rubyver=	pre-configure
SUBST_MESSAGE.rubyver=	Fixing asciidoctor executable name.

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
FORCE_C_STD=		gnu11
MESON_ARGS+=		-Dwith_docs=true
REPLACE_SH+=		bin/picom-trans
PYTHON_FOR_BUILD_ONLY=	tool
INSTALLATION_DIRS+=	share/examples/picom share/examples/picom/xdg/autostart

CONF_FILES+=	share/examples/picom/xdg/autostart/picom.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/picom.desktop
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart

post-install:
	${INSTALL_DATA} ${WRKSRC}/picom.sample.conf ${DESTDIR}${PREFIX}/share/examples/picom/picom.sample.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/autostart/picom.desktop ${DESTDIR}${PREFIX}/share/examples/picom/xdg/autostart

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
