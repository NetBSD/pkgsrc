# $NetBSD: Makefile,v 1.1.1.1 2000/02/03 19:41:03 drochner Exp $
#

DISTNAME=	Xbae-4.7.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.lesstif.org/Xbae.html

USE_MOTIF=	yes
USE_LIBTOOL=	yes

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--disable-build-12 \
			--enable-build-20 --enable-default-20

.include "../../mk/bsd.pkg.mk"
