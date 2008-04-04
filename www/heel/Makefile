# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:22:53 jlam Exp $

DISTNAME=	heel-0.6.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://copiousfreetime.rubyforge.org/heel/
COMMENT=	Static file web server based on mongrel

DEPENDS+=	mongrel>=1.0.1:../../www/mongrel
DEPENDS+=	rake>=0.7.3:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=0.7.4.215:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=0.3.0:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.15:../../mail/ruby-mime-types

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
