# $NetBSD: Makefile,v 1.21 2005/04/11 21:47:53 tv Exp $
#

DISTNAME=		glibwww-0.2
PKGREVISION=		7
CATEGORIES=		www gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glibwww/0.2/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Event register functions that use the glib event loop

USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../www/libwww/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
