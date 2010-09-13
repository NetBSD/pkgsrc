# $NetBSD: Makefile,v 1.3 2010/09/13 14:12:15 taca Exp $

DISTNAME=	webby-0.9.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webby.rubyforge.org/
COMMENT=	Static web page generator
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-heel>=0.6.0:../../www/heel
DEPENDS+=	${RUBY_PKGPREFIX}-directory-watcher>=1.1.1:../../sysutils/ruby-directory-watcher
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6:../../textproc/ruby-hpricot
DEPENDS+=	${RUBY_PKGPREFIX}-logging>=0.7.1:../../devel/ruby-logging
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec

CONFLICTS+=	ruby[1-9][0-9]-webby-[0-9]* webby-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
