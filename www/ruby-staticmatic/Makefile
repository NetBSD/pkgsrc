# $NetBSD: Makefile,v 1.1.1.1 2009/11/01 03:16:58 seb Exp $

DISTNAME=	staticmatic-0.10.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://staticmatic.rubyforge.org/
COMMENT=	Lightweight static site framework

GEM_BUILD=	gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-haml>=2.0.0:../../textproc/ruby-haml
DEPENDS+=	mongrel>=1.1.5:../../www/mongrel

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
