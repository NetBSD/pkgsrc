# $NetBSD: Makefile,v 1.11.6.1 2009/10/21 12:44:37 tron Exp $

.include "../../x11/xlockmore/Makefile.common"

PKGREVISION=	1
PKGNAME=	${DISTNAME:S/-/-lite-/}
COMMENT=	"lite" version of xlockmore

CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-gltt
CONFIGURE_ARGS+=	--without-ttf
CONFIGURE_ARGS+=	--without-freetype
CONFIGURE_ARGS+=	--without-opengl
CONFIGURE_ARGS+=	--without-mesa
CONFIGURE_ARGS+=	--without-rplay
CONFIGURE_ARGS+=	--without-esound
CONFIGURE_ARGS+=	--without-gtk2
CONFIGURE_ARGS+=	--without-gtk

PLIST_SUBST+=    LITE="@comment Not in lite version: "

.include "../../mk/bsd.pkg.mk"
