# $NetBSD: Makefile,v 1.16 2011/04/22 13:45:14 obache Exp $

DISTNAME=		rep-gtk-0.90.4
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		1
CATEGORIES=		x11 lang
MASTER_SITES=		http://download.tuxfamily.org/sawfish/rep-gtk/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://rep-gtk.sourceforge.net/
COMMENT=		librep bindings for gtk2 (used by wm/sawfish)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		rep-gtk-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE=	rep-gtk.pc.in

.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
