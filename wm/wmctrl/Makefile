# $NetBSD: Makefile,v 1.2 2004/03/07 05:27:54 snj Exp $

DISTNAME=		wmctrl-1.05
CATEGORIES=		wm
MASTER_SITES=		http://sweb.cz/tripie/utils/wmctrl/dist/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://sweb.cz/tripie/utils/wmctrl/
COMMENT=		Command line interface to an EWMH-compliant WM

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
