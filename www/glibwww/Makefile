# $NetBSD: Makefile,v 1.16 2004/03/16 11:04:19 tron Exp $

DISTNAME=		glibwww-0.2
PKGREVISION=		6
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

.include "../../databases/db4/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
