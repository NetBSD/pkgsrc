# $NetBSD: Makefile,v 1.14 2015/07/04 16:18:40 joerg Exp $

DISTNAME=		rxvt-2.7.10
PKGNAME=		rclock-2.7.10
CATEGORIES=		x11 time
MASTER_SITES=           ftp://ftp.rxvt.org/pub/rxvt/ \
                        ftp://mason.primenet.com.au/pub/rxvt/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Analog clock for X w/appointment reminder and mail notification

GNU_CONFIGURE=		yes
BUILD_TARGET=		clock

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
