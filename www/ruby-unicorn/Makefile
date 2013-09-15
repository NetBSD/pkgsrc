# $NetBSD: Makefile,v 1.5 2013/09/15 18:01:47 taca Exp $

DISTNAME=	unicorn-4.6.3
CATEGORIES=	www

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://unicorn.bogomips.org/
COMMENT=	Rack HTTP server for fast clients and Unix
LICENSE=	ruby-license OR gnu-gpl-v2 OR gnu-gpl-v3

CONFLICTS=	ruby[1-9][0-9]-unicorn-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-kgio>=2.6<3:../../devel/ruby-kgio
DEPENDS+=	${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-raindrops>=0.7<1:../../www/ruby-raindrops

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
