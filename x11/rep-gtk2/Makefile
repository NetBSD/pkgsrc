# $NetBSD: Makefile,v 1.13 2010/11/15 22:59:11 abs Exp $

DISTNAME=		rep-gtk-0.90.2
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		2
CATEGORIES=		x11 lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rep-gtk/}
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
