# $NetBSD: Makefile,v 1.20 2017/08/16 20:45:46 wiz Exp $

DISTNAME=		fcgi-2.4.0
PKGREVISION=		2
CATEGORIES=		www devel
#MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
