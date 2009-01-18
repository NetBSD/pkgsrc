# $NetBSD: Makefile,v 1.17 2009/01/18 14:56:17 roy Exp $

DISTNAME=		fcgi-2.4.0
PKGREVISION=		1
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
