# $NetBSD: Makefile,v 1.39 2020/01/18 16:23:14 taca Exp $

DISTNAME=	json-2.3.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flori.github.com/json
COMMENT=	Native extension implementation of JSON for Ruby
LICENSE=	ruby-license

USE_GCC_RUNTIME=	yes

RUBY_VERSIONS_ACCEPTED=	24 25 26

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
