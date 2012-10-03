# $NetBSD: Makefile,v 1.20.2.1 2012/10/03 12:09:41 spz Exp $
#

DISTNAME=     selectwm-0.4.1
PKGREVISION=  17
CATEGORIES=   wm
MASTER_SITES= http://ordiluc.net/selectwm/

MAINTAINER=   tonio@NetBSD.org
HOMEPAGE=     http://ordiluc.net/selectwm/
COMMENT=      Simple GTK2 application to select window manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=       pkg-config
USE_PKGLOCALEDIR= yes
GNU_CONFIGURE=    yes

CONFIGURE_ARGS+=  --without-included-gettext

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
