# $NetBSD: Makefile,v 1.10 2004/02/14 17:21:54 jlam Exp $

DISTNAME=		fcgi-2.4.0
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

USE_BUILDLINK2=		YES
USE_GCC_SHLIB=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
