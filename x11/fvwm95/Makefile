# $NetBSD: Makefile,v 1.17 1999/07/27 21:34:32 tron Exp $
# FreeBSD: Makefile,v 1.17 1997/12/24 01:21:18 alex Exp
#

DISTNAME=	fvwm95-2.0.43a-Autoconf
PKGNAME=	fvwm95-2.0.43a
CATEGORIES=	x11
MASTER_SITES=	ftp://mitac11.uia.ac.be/pub/fvwm95/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://mitac11.uia.ac.be/html-test/fvwm95.html

DEPENDS+=	rplay-3.2.0b6:../../audio/rplay
DEPENDS+=	xpmroot-2.2:../../x11/xpmroot

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib

post-install:
		@${INSTALL_MAN}	${WRKSRC}/fvwm/fvwm95.man \
			${PREFIX}/man/man1/fvwm95.1

.include "../../mk/bsd.pkg.mk"
