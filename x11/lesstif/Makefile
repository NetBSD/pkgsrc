# $NetBSD: Makefile,v 1.39 1999/09/03 19:45:11 drochner Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=	lesstif-0.88.9
CATEGORIES=	x11
MASTER_SITES=	ftp://linux.gt.ed.net/pub/linux/libs/lesstif/srcdist/ \
		ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.lesstif.org/

GNU_CONFIGURE=  yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --with-x --enable-production
CONFIGURE_ARGS+=	--disable-build-12 --enable-default-20
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ENV=		CCFLAGS="${CFLAGS}"

.include "../../mk/bsd.pkg.mk"
