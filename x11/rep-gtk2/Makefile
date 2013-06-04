# $NetBSD: Makefile,v 1.29 2013/06/04 22:17:31 tron Exp $

DISTNAME=	rep-gtk-0.90.4
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
PKGREVISION=	11
CATEGORIES=	x11 lang
MASTER_SITES=	http://download.tuxfamily.org/sawfish/rep-gtk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rep-gtk.sourceforge.net/
COMMENT=	GTK2 librep bindings (used by wm/sawfish)

CONFLICTS=	rep-gtk-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE=	rep-gtk.pc.in

.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
