# $NetBSD: Makefile,v 1.11 2004/04/27 03:19:59 snj Exp $

DISTNAME=		fcgi-2.4.0
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

USE_BUILDLINK3=		YES
USE_GCC_SHLIB=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
