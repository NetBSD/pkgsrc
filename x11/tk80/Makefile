# $NetBSD: Makefile,v 1.26 2000/06/01 11:23:48 rh Exp $
# FreeBSD Id: Makefile,v 1.4 1997/10/01 09:20:31 tg Exp
#

DISTNAME=	tk8.0.5
PKGNAME=	tk-8.0.5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.scriptics.com/

DEPENDS+=	tcl-8.0.5:../../lang/tcl80

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes

USE_X11=	yes

# let libtool look after shared libraries
USE_PKGLIBTOOL=	yes
CONFIGURE_ARGS+=	--disable-shared

test:
	cd ${WRKSRC}; ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
