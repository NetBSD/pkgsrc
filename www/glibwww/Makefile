# $NetBSD: Makefile,v 1.8 2002/08/28 15:53:09 jlam Exp $
#

DISTNAME=		glibwww-0.2
PKGREVISION=		2
CATEGORIES=		www gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/glibwww/}

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
