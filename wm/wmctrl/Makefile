# $NetBSD: Makefile,v 1.8 2006/02/05 23:11:15 joerg Exp $

DISTNAME=		wmctrl-1.05
PKGREVISION=	2
CATEGORIES=		wm
MASTER_SITES=		http://sweb.cz/tripie/utils/wmctrl/dist/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://sweb.cz/tripie/utils/wmctrl/
COMMENT=		Command line interface to an EWMH-compliant WM

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
