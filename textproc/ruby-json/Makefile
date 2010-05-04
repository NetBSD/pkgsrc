# $NetBSD: Makefile,v 1.4 2010/05/04 02:46:50 taca Exp $

DISTNAME=	json-1.4.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://json.rubyforge.org/
COMMENT=	Native extension implementation of JSON for Ruby
LICENSE=	ruby-license

GEM_BUILD=	gemspec

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
