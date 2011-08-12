# $NetBSD: Makefile,v 1.5 2011/08/12 17:36:31 taca Exp $

DISTNAME=	heel-2.0.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://copiousfreetime.rubyforge.org/heel/
COMMENT=	Static file web server based on Rack and Thin
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-thin>=1.2.0<1.3:../../www/thin
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=0.8.260:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=0.3.2:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16<2:../../mail/ruby-mime-types

CONFLICTS+=	ruby[1-9][0-9]-heel-[0-9]* heel-[0-9]*

OVERRIDE_GEMSPEC+=	coderay>=0.8.260 launchy>=0.3.2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
