# $NetBSD: Makefile,v 1.53 2023/11/14 14:03:20 wiz Exp $

DISTNAME=	rep-gtk_0.90.8.3
PKGNAME=	${DISTNAME:S/gtk_/gtk2-/}
PKGREVISION=	10
CATEGORIES=	x11 lang
MASTER_SITES=	http://download.tuxfamily.org/librep/rep-gtk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sawfish.wikia.com/
COMMENT=	GTK2 librep bindings (used by wm/sawfish)
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config automake autoconf autoreconf
PKGCONFIG_OVERRIDE=	rep-gtk.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
