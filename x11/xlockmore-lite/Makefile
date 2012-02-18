# $NetBSD: Makefile,v 1.14 2012/02/18 23:50:33 elric Exp $

.include "../../x11/xlockmore/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-lite-/}
PKGREVISION=	1
COMMENT=	"lite" version of xlockmore

CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-gltt
CONFIGURE_ARGS+=	--without-ttf
CONFIGURE_ARGS+=	--without-freetype
CONFIGURE_ARGS+=	--without-opengl
CONFIGURE_ARGS+=	--without-magick
CONFIGURE_ARGS+=	--without-mesa
CONFIGURE_ARGS+=	--without-rplay
CONFIGURE_ARGS+=	--without-esound
CONFIGURE_ARGS+=	--without-gtk2
CONFIGURE_ARGS+=	--without-gtk

PLIST_SUBST+=    LITE="@comment Not in lite version: "

.include "../../mk/bsd.pkg.mk"
