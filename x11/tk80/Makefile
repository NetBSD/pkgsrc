# $NetBSD: Makefile,v 1.17 1998/07/04 04:11:34 mycroft Exp $
# FreeBSD Id: Makefile,v 1.4 1997/10/01 09:20:31 tg Exp
#

DISTNAME=	tk8.0p2
PKGNAME=	tk-8.0p2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	tcl-8.0p2:../../lang/tcl80

WRKSRC=		${WRKDIR}/tk8.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=  PORTSDIR=${.CURDIR}/../../../../..

post-install:
	${LDCONFIG} || ${TRUE}

test:
	cd ${WRKSRC}; make test

.include "../../mk/bsd.pkg.mk"
