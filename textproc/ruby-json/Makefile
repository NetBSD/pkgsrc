# $NetBSD: Makefile,v 1.8.4.1 2011/02/27 00:26:27 tron Exp $

DISTNAME=	json-1.4.6
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flori.github.com/json
COMMENT=	Native extension implementation of JSON for Ruby
LICENSE=	ruby-license

GEM_CLEANBUILD=	ext/json/ext/generator/* ext/json/ext/parser/*
REPLACE_RUBY=	tools/fuzz.rb tools/server.rb

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

REPLACE_RUBY_DIRS=	tools

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
