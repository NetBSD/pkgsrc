# $NetBSD: Makefile,v 1.59 2025/05/18 10:18:27 zafer Exp $

DISTNAME=	rep-gtk_0.90.8.3
PKGNAME=	${DISTNAME:S/gtk_/gtk2-/}
PKGREVISION=	15
CATEGORIES=	x11 lang
MASTER_SITES=	https://www.aydogan.net/distfiles/x11/
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
