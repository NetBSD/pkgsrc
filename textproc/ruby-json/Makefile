# $NetBSD: Makefile,v 1.43 2021/03/07 14:29:39 taca Exp $

DISTNAME=	json-2.5.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flori.github.com/json
COMMENT=	Native extension implementation of JSON for Ruby
LICENSE=	ruby-license

USE_GCC_RUNTIME=	yes

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
