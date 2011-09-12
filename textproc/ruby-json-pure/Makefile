# $NetBSD: Makefile,v 1.11 2011/09/12 13:42:30 taca Exp $

DISTNAME=	json_pure-1.5.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flori.github.com/json
COMMENT=	Pure Ruby implementation of JSON
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-spruz>=0.2.8<0.3:../../devel/ruby-spruz

REPLACE_RUBY=	tools/fuzz.rb tools/server.rb

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
