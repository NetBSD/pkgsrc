# $NetBSD: Makefile,v 1.6 2005/07/21 16:29:58 wiz Exp $

DISTNAME=		wmctrl-1.05
PKGREVISION=	1
CATEGORIES=		wm
MASTER_SITES=		http://sweb.cz/tripie/utils/wmctrl/dist/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://sweb.cz/tripie/utils/wmctrl/
COMMENT=		Command line interface to an EWMH-compliant WM

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
