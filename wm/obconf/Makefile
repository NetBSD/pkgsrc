# $NetBSD: Makefile,v 1.1.1.1 2003/12/13 21:10:20 xtraeme Exp $

DISTNAME=		obconf-1.5
CATEGORIES=		x11 wm
MASTER_SITES=		http://icculus.org/openbox/obconf/

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://www.openbox.org/obconf/
COMMENT=		Tool for configuring the Openbox window manager

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../devel/libglade2/buildlink2.mk"
.include "../../wm/openbox3/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
