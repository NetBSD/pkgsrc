# $NetBSD: Makefile,v 1.4 2010/09/13 14:12:14 taca Exp $

DISTNAME=	heel-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://copiousfreetime.rubyforge.org/heel/
COMMENT=	Static file web server based on Rack and Thin
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-thin>=1.2.0:../../www/thin
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=0.8.260:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=0.3.2:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types

CONFLICTS+=	ruby[1-9][0-9]-heel-[0-9]* heel-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
