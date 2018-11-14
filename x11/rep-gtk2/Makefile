# $NetBSD: Makefile,v 1.42 2018/11/14 22:22:49 kleink Exp $

DISTNAME=	rep-gtk-0.90.8.1
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
PKGREVISION=	9
CATEGORIES=	x11 lang
MASTER_SITES=	http://download.tuxfamily.org/librep/rep-gtk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sawfish.wikia.com/
COMMENT=	GTK2 librep bindings (used by wm/sawfish)

CONFLICTS=	rep-gtk-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE=	rep-gtk.pc.in

.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
