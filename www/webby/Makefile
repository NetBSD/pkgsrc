# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:27:12 jlam Exp $

DISTNAME=	webby-0.8.2
CATEGORES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webby.rubyforge.org/
COMMENT=	Static web page generator

DEPENDS+=	heel>=0.6.0:../../www/heel
DEPENDS+=	rake>=0.8.1:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-directory-watcher>=1.1.1:../../sysutils/ruby-directory-watcher
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6:../../textproc/ruby-hpricot
DEPENDS+=	${RUBY_PKGPREFIX}-logging>=0.7.1:../../devel/ruby-logging
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
