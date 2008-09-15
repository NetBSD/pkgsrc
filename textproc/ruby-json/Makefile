# $NetBSD: Makefile,v 1.2 2008/09/15 08:38:01 taca Exp $

DISTNAME=	json-1.1.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://json.rubyforge.org/
COMMENT=	Native extension implementation of JSON for Ruby

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
