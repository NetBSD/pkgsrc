# $NetBSD: Makefile,v 1.67 2026/10/19 23:23:59 gutteridge Exp $

DISTNAME=	rep-gtk_0.90.8.3
PKGNAME=	${DISTNAME:S/gtk_/gtk2-/}
PKGREVISION=	21
CATEGORIES=	x11 lang
MASTER_SITES=	https://www.aydogan.net/distfiles/x11/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sawfish.wikia.com/
COMMENT=	GTK2 librep bindings (used by wm/sawfish)
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config automake autoconf autoreconf
PKGCONFIG_OVERRIDE=	rep-gtk.pc.in

CFLAGS+=	-Wno-implicit-function-declaration -Wno-incompatible-pointer-types
CFLAGS+=	-Wno-int-conversion

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
