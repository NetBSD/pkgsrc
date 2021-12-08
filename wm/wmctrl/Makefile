# $NetBSD: Makefile,v 1.20 2021/12/08 16:06:52 adam Exp $

DISTNAME=		wmctrl-1.07
PKGREVISION=		6
CATEGORIES=		wm
MASTER_SITES=		https://sites.google.com/site/tstyblo/wmctrl/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		https://sites.google.com/site/tstyblo/wmctrl
COMMENT=		Command line interface to an EWMH-compliant WM
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
