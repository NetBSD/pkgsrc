# $NetBSD: Makefile,v 1.1.1.1.2.3 2002/06/30 04:00:45 jlam Exp $
#

DISTNAME=	elinks-0.3.0
CATEGORIES=	www
MASTER_SITES=	http://elinks.pld.org.pl/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://elinks.pld.org.pl/
COMMENT=	Extended/Enhanced Links (elinks)

CONFLICTS=	links-[0-9]* links-gui-[0-9]*

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
