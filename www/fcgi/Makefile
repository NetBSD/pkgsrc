# $NetBSD: Makefile,v 1.2 2002/08/01 06:40:55 jlam Exp $

DISTNAME=		fcgi-2.2.2
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
