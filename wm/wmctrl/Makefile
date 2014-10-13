# $NetBSD: Makefile,v 1.17 2014/10/13 18:52:25 snj Exp $

DISTNAME=		wmctrl-1.07
PKGREVISION=		4
CATEGORIES=		wm
MASTER_SITES=		http://tomas.styblo.name/wmctrl/dist/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://tomas.styblo.name/wmctrl/
COMMENT=		Command line interface to an EWMH-compliant WM
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
