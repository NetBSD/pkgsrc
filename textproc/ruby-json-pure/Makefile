# $NetBSD: Makefile,v 1.29 2020/05/05 05:53:07 taca Exp $

DISTNAME=	json_pure-2.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flori.github.com/json
COMMENT=	Pure Ruby implementation of JSON
LICENSE=	ruby-license

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
