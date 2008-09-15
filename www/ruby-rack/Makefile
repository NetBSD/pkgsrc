# $NetBSD: Makefile,v 1.2 2008/09/15 08:31:47 taca Exp $

DISTNAME=	rack-0.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.rubyforge.org/
COMMENT=	Ruby webserver interface

GEM_BUILD=	gemspec

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
