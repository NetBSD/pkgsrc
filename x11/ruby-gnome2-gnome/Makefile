# $NetBSD: Makefile,v 1.11 2007/09/19 23:19:14 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnome-${VERSION}
COMMENT=		Ruby binding of libgnome/libgnomeui-2.x
PKGREVISION=		3
CATEGORIES=		gnome x11

CONFLICTS+=		ruby-gnome2-gnome-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gnome

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas

USE_TOOLS+=		pkg-config

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
