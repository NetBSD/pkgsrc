# $NetBSD: Makefile,v 1.38 2017/06/12 16:34:13 taca Exp $

DISTNAME=	json-2.1.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flori.github.com/json
COMMENT=	Native extension implementation of JSON for Ruby
LICENSE=	ruby-license

USE_GCC_RUNTIME=	yes

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
