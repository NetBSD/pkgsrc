# $NetBSD: Makefile,v 1.8.2.1 2002/05/11 02:09:28 jlam Exp $
#

DISTNAME=	links-0.96
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
USE_BUILDLINK2_ONLY=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
