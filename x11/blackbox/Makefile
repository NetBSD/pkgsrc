# $NetBSD: Makefile,v 1.2 2000/07/11 10:18:03 agc Exp $

DISTNAME=	blackbox-0.51.3.1
CATEGORIES=	x11
MASTER_SITES=	ftp://portal.alug.org/pub/blackbox/0.5x.x/ \
		ftp://ftp.dti.ad.jp/pub/X/blackbox/0.5x.x/

MAINTAINER=	djp@cpl.herston.uq.edu.au
HOMEPAGE=	http://blackbox.alug.org/

USE_X11BASE=            yes
GNU_CONFIGURE=          yes

CONFIGURE_ARGS+=	--prefix=${X11PREFIX} \
			--x-includes=${X11BASE}/include \
			--x-libraries=${X11BASE}/lib \
			--enable-kde

.include "../../mk/bsd.pkg.mk"
