# $NetBSD: Makefile,v 1.19.4.1 2013/02/14 15:52:15 tron Exp $

DISTNAME=	json_pure-1.7.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flori.github.com/json
COMMENT=	Pure Ruby implementation of JSON
LICENSE=	ruby-license

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
