# $NetBSD: Makefile,v 1.10 2002/06/17 10:33:54 wiz Exp $
#

DISTNAME=	links-0.97
CATEGORIES=	www
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~mikulas/links/download/ \
		http://www.add.com.pl/links/download/			 \
		http://ice.dammit.lt/links/download/			 \
		http://mirrors.oven.com/links/				 \
		http://links.sourceforge.net/download/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://artax.karlin.mff.cuni.cz/~mikulas/links/
COMMENT=	Lynx-like text WWW browser

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
