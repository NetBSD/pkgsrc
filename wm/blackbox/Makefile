# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:46 wiz Exp $
#

DISTNAME=	blackbox-0.61.1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://portal.alug.org/pub/blackbox/0.6x.x/

MAINTAINER=	djp@cpl.herston.uq.edu.au
HOMEPAGE=	http://blackbox.alug.org/

USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--prefix=${X11PREFIX} \
			--x-includes=${X11BASE}/include \
			--x-libraries=${X11BASE}/lib \
			--enable-kde

HAS_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
