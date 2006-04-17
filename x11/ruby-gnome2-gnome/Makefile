# $NetBSD: Makefile,v 1.5 2006/04/17 13:47:01 wiz Exp $
#

PKGNAME=		ruby-gnome2-gnome-${VERSION}
COMMENT=		Ruby binding of libgnome/libgnomeui-2.x
PKGREVISION=		4
CATEGORIES=		gnome x11

RUBY_EXTCONF_SUBDIRS=	gnome

DEPENDS+=		ruby-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas

USE_TOOLS+=		pkg-config

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
