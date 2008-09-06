# $NetBSD: Makefile,v 1.15 2008/09/06 20:54:35 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-panelapplet-${VERSION}
COMMENT=		Ruby binding of libpanel-applet-2.6.x
PKGREVISION=		1
CATEGORIES=		x11 gnome

CONFLICTS+=		ruby-gnome2-panelapplet-[0-9]*

RUBY_EXTCONF_SUBDIRS=	glib panel-applet

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gnome>=${VERSION}:../../x11/ruby-gnome2-gnome

USE_TOOLS+=		pkg-config

.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
