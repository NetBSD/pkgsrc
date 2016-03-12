# $NetBSD: Makefile,v 1.5 2016/03/12 09:27:19 tnn Exp $
#

DISTNAME=		libXprintUtil-1.0.1
CATEGORIES=		x11 print
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Print Utility Library

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

# The configure script insists that it wants a working C++ preprocessor.
# Regenerating configure with a newer version of autoconf makes the check
# go away. It is easier to just give it what it wants until upstream fixes
# this.
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	xprintutil.pc.in

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
