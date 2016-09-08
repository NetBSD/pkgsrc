# $NetBSD: Makefile,v 1.34 2016/09/08 15:19:19 joerg Exp $

DISTNAME=	json-1.8.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flori.github.com/json
COMMENT=	Native extension implementation of JSON for Ruby
LICENSE=	ruby-license

USE_GCC_RUNTIME=	yes

RUBY_VERSIONS_ACCEPTED= 18 21 22 23

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
