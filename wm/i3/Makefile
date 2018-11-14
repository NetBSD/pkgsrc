# $NetBSD: Makefile,v 1.27 2018/11/14 22:22:33 kleink Exp $

DISTNAME=	i3-4.15
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	https://i3wm.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://i3wm.org/
COMMENT=	Improved dynamic tiling window manager
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake bison lex yacc pkg-config perl:run
USE_LANGUAGES=	c99

CONFIGURE_ARGS+=--disable-builddir

LDFLAGS.SunOS+=	-lgen -liconv -lsocket

PKG_SYSCONFSUBDIR=	i3

EGDIR=		${PREFIX}/share/examples/i3
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/config.keycodes ${PKG_SYSCONFDIR}/config.keycodes

REPLACE_PERL+=	i3-dmenu-desktop
REPLACE_PERL+=	i3-migrate-config-to-v4
REPLACE_PERL+=	i3-save-tree

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-xrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
