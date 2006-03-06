# $NetBSD: Makefile,v 1.4 2006/03/06 00:18:27 wiz Exp $
#

PKGNAME=		ruby-gnome2-panelapplet-${VERSION}
COMMENT=		Ruby binding of libpanel-applet-2.6.x
PKGREVISION=		3
CATEGORIES=		x11 gnome

RUBY_EXTCONF_SUBDIRS=	panel-applet

DEPENDS+=		ruby-gnome2-gnome>=${VERSION}:../../x11/ruby-gnome2-gnome

USE_TOOLS+=		pkg-config

.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
