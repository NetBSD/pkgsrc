# $NetBSD: Makefile,v 1.6 2010/06/15 13:35:52 obache Exp $

DISTNAME=	json-1.4.3
PKGREVISION=	1
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

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
