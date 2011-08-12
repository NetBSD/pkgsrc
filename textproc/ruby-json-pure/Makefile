# $NetBSD: Makefile,v 1.10 2011/08/12 17:20:20 taca Exp $

DISTNAME=	json_pure-1.5.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flori.github.com/json
COMMENT=	Pure Ruby implementation of JSON
LICENSE=	ruby-license

REPLACE_RUBY=	tools/fuzz.rb tools/server.rb

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
