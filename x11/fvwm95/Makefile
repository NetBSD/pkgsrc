# $NetBSD: Makefile,v 1.7 1998/04/15 10:38:53 agc Exp $
# FreeBSD: Makefile,v 1.17 1997/12/24 01:21:18 alex Exp
#

DISTNAME=	fvwm95-2.0.43a-Autoconf
PKGNAME=	fvwm95-2.0.43a
CATEGORIES=	x11
MASTER_SITES=	ftp://mitac11.uia.ac.be/pub/fvwm95/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4.:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=	${LOCALBASE}/lib/librplay.a:${PORTSDIR}/audio/rplay
RUN_DEPENDS=	xpmroot:${PORTSDIR}/x11/xpmroot

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib

MAN1=		fvwm95.1

post-install:
		@${INSTALL_MAN}	${WRKSRC}/fvwm/fvwm95.man \
			${PREFIX}/man/man1/fvwm95.1

.include "../../mk/bsd.pkg.mk"
