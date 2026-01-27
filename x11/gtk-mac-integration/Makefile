# $NetBSD: Makefile,v 1.35 2026/01/27 08:40:55 wiz Exp $

DISTNAME=	gtk-mac-integration-3.0.1
PKGREVISION=	16
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-mac-integration/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gtk-mac-integration
COMMENT=	OS X integration for GTK
LICENSE=	gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	Darwin-*-*

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk2
CONFIGURE_ARGS+=	--with-gtk3

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
