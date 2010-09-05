# $NetBSD: Makefile,v 1.7 2010/09/05 02:13:51 obache Exp $

DISTNAME=	json-1.4.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://json.rubyforge.org/
COMMENT=	Native extension implementation of JSON for Ruby
LICENSE=	ruby-license

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	ext/json/ext/generator/* ext/json/ext/parser/*

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

REPLACE_RUBY_DIRS=	tools

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
