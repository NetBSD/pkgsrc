# $NetBSD: Makefile,v 1.18 2018/02/25 16:15:09 wiz Exp $

DISTNAME=		wmctrl-1.07
PKGREVISION=		4
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
