# $NetBSD: Makefile,v 1.11 2015/02/04 15:13:28 taca Exp $

DISTNAME=	heel-3.1.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/copiousfreetime/heel/
COMMENT=	Static file web server based on Rack and Thin
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-puma>=2.0<3:../../www/ruby-puma
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.1<2:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=2.3<3:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types1>=1.25<2:../../mail/ruby-mime-types1

CONFLICTS+=	ruby[1-9][0-9][0-9]-heel-[0-9]* heel-[0-9]*

OVERRIDE_GEMSPEC+=	coderay>=0.8.260 launchy>=0.3.2 thin>=1.2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
