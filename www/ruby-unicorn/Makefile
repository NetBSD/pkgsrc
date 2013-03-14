# $NetBSD: Makefile,v 1.4 2013/03/14 16:24:21 taca Exp $

DISTNAME=	unicorn-4.6.2
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
