# $NetBSD: Makefile,v 1.3 2002/10/09 00:04:27 jlam Exp $

DISTNAME=		fcgi-2.2.2
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
