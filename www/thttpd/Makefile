# $NetBSD: Makefile,v 1.1.1.1 1999/04/10 22:01:10 tron Exp $
#

DISTNAME=	thttpd-2.04
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://http://www.acme.com/software/thttpd/

GNU_CONFIGURE=	yes

pre-install:
	${MKDIR} ${PREFIX}/www
	${MKDIR} ${PREFIX}/www/cgi-bin

.include "../../mk/bsd.pkg.mk"
