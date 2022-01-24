# $NetBSD: Makefile,v 1.24 2022/01/24 18:10:32 micha Exp $

.include "../../x11/xlockmore/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-lite-/}
#PKGREVISION=	1
COMMENT=	"lite" version of xlockmore

CONFLICTS+=	xlockmore-[0-9]*

CONFIGURE_ARGS+=	--without-esound
CONFIGURE_ARGS+=	--without-freetype
CONFIGURE_ARGS+=	--without-ftgl
CONFIGURE_ARGS+=	--without-gltt
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-gtk2
CONFIGURE_ARGS+=	--without-libpng
CONFIGURE_ARGS+=	--without-magick
CONFIGURE_ARGS+=	--without-mesa
CONFIGURE_ARGS+=	--without-opengl
CONFIGURE_ARGS+=	--without-rplay
CONFIGURE_ARGS+=	--without-ttf
CONFIGURE_ARGS+=	--without-xpm

PLIST_SUBST+=	LITE="@comment Not in lite version: "

.include "../../mk/bsd.pkg.mk"
