# $NetBSD: Makefile,v 1.4 2011/08/13 00:34:46 taca Exp $

DISTNAME=	webby-0.9.4
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webby.rubyforge.org/
COMMENT=	Static web page generator
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-directory-watcher>=1.1.2:../../sysutils/ruby-directory-watcher
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6.0:../../textproc/ruby-hpricot
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=0.3.2:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-logging>=0.9.7:../../devel/ruby-logging
DEPENDS+=	${RUBY_PKGPREFIX}-loquacious>=1.3.0:../../devel/ruby-loquacious
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.2.2:../../devel/ruby-rspec

CONFLICTS+=	ruby[1-9][0-9]-webby-[0-9]* webby-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
