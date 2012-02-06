# $NetBSD: Makefile,v 1.1.1.1 2012/02/06 12:40:36 fhajny Exp $

DISTNAME=	unicorn-4.2.0
CATEGORIES=	www

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://unicorn.bogomips.org/
COMMENT=	Rack HTTP server for fast clients and Unix
LICENSE=	ruby-license OR gnu-gpl-v2 OR gnu-gpl-v3

CONFLICTS=	ruby[1-9][0-9]-unicorn-[0-9]*
DEPENDS+=	${RUBY_PKGPREFIX}-kgio>=2.6:../../devel/ruby-kgio
DEPENDS+=	${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-raindrops>=0.7:../../www/ruby-raindrops

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
