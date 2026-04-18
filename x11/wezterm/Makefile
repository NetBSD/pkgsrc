# $NetBSD: Makefile,v 1.11 2026/04/18 14:56:36 ktnb Exp $

# VERSION must match the output of:
# git -c "core.abbrev=8" show -s "--format=%cd-%h" "--date=format:%Y%m%d-%H%M%S"
DISTNAME=	wezterm-20260117.154428
VERSION=	${PKGVERSION_NOREV:S/./-/}-${GITHUB_TAG:C/(........).*/\1/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wezterm/}
GITHUB_TAG=	05343b387085842b434d267f91b6b0ec157e4331

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://wezterm.org/
COMMENT=	Powerful cross-platform terminal emulator and multiplexer
LICENSE=	mit AND ofl-v1.1

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

DEPENDS+=	JetBrainsMono-ttf-[0-9]*:../../fonts/JetBrainsMono-ttf
DEPENDS+=	nerd-fonts-Symbols-[0-9]*:../../fonts/nerd-fonts-Symbols
DEPENDS+=	roboto-fonts-[0-9]*:../../fonts/roboto-fonts
DEPENDS+=	noto-emoji-ttf-[0-9]*:../../fonts/noto-emoji-ttf

# xcb-imdkit-rs needs a submodule
GITHUB_SUBMODULES+=	fcitx xcb-imdkit 44f5c8219bcae9e6afc2391dc50486efcf0bdf06 ../xcb-imdkit-rs-${XCB_IMDKIT_RS_REV}/deps/xcb-imdkit

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
FINL_UNICODE_REV=	a1892f26245529f2ef3877a9ebd610c96cec07a6
XCB_IMDKIT_RS_REV=	212330f7c6c37794d78061a773e8f4f9e4785bbb
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		finl_unicode-${FINL_UNICODE_REV}.tar.gz
DISTFILES+=		xcb-imdkit-rs-${XCB_IMDKIT_RS_REV}.tar.gz

SITES.finl_unicode-${FINL_UNICODE_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=wez/}finl_unicode/archive/${FINL_UNICODE_REV}.tar.gz
SITES.xcb-imdkit-rs-${XCB_IMDKIT_RS_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=wez/}xcb-imdkit-rs/archive/${XCB_IMDKIT_RS_REV}.tar.gz

CHECK_PORTABILITY_SKIP=	get-deps

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/examples/wezterm
INSTALLATION_DIRS+=	share/fish/completions
INSTALLATION_DIRS+=	share/icons/hicolor/symbolic/apps
INSTALLATION_DIRS+=	share/metainfo
INSTALLATION_DIRS+=	share/zsh/site-functions

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.xcb-util}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxkbcommon}/lib

CARGO_NO_DEFAULT_FEATURES=	yes
CARGO_FEATURES+=		distro-defaults

post-extract:
	${ECHO} ${VERSION} > ${WRKSRC}/.tag

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wezterm \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wezterm-gui \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wezterm-mux-server \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/strip-ansi-escapes \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/assets/open-wezterm-here \
		${DESTDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sync-color-schemes \
#		${DESTDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/generate-bidi \
#		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/assets/wezterm.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/wezterm
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/fish \
		${DESTDIR}${PREFIX}/share/fish/completions/wezterm.fish
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_wezterm
	${INSTALL_DATA} ${WRKSRC}/assets/icon/wezterm-icon.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/symbolic/apps/org.wezfurlong.wezterm.svg
	${INSTALL_DATA} ${WRKSRC}/assets/wezterm.appdata.xml \
		${DESTDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/assets/shell-integration/wezterm.sh \
		${DESTDIR}${PREFIX}/share/examples/wezterm

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND:tl} == yes
.include "../../devel/wayland/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../lang/libunwind/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
