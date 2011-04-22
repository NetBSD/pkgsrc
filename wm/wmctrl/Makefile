# $NetBSD: Makefile,v 1.12 2011/04/22 13:44:56 obache Exp $

DISTNAME=		wmctrl-1.07
PKGREVISION=		1
CATEGORIES=		wm
MASTER_SITES=		http://sweb.cz/tripie/utils/wmctrl/dist/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://sweb.cz/tripie/utils/wmctrl/
COMMENT=		Command line interface to an EWMH-compliant WM

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
