# $NetBSD: Makefile,v 1.15 2004/01/03 18:49:55 reed Exp $
#

DISTNAME=		glibwww-0.2
PKGREVISION=		5
CATEGORIES=		www gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glibwww/0.2/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Event register functions that use the glib event loop

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../www/libwww/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
