# $NetBSD: Makefile,v 1.8 2007/01/29 06:42:34 minskim Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnome-${VERSION}
COMMENT=		Ruby binding of libgnome/libgnomeui-2.x
CATEGORIES=		gnome x11

CONFLICTS+=		ruby-gnome2-gnome-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gnome

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas

USE_TOOLS+=		pkg-config

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
