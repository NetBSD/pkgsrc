# $NetBSD: Makefile,v 1.3 2008/06/20 01:09:43 joerg Exp $
#

DISTNAME=	varnish-1.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=varnish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://varnish-cache.org/
COMMENT=	High-performace HTTP accelerator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
