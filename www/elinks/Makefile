# $NetBSD: Makefile,v 1.2 2002/06/30 04:02:54 jlam Exp $
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
USE_BUILDLINK_ONLY=	YES

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
