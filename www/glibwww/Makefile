# $NetBSD: Makefile,v 1.25 2006/07/19 19:14:39 jlam Exp $
#

DISTNAME=		glibwww-0.2
PKGREVISION=		9
CATEGORIES=		www gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glibwww/0.2/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Event register functions that use the glib event loop

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../www/libwww/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
