# $NetBSD: Makefile,v 1.9 2002/10/19 10:54:59 rh Exp $
#

DISTNAME=		glibwww-0.2
PKGREVISION=		2
CATEGORIES=		www gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glibwww/0.2/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		event register functions that use the glib event loop

BUILDLINK_DEPENDS.gnome-libs=	gnome-libs>=1.4.1.2nb1

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../www/libwww/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
