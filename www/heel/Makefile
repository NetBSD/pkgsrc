# $NetBSD: Makefile,v 1.14 2018/09/24 02:28:58 taca Exp $

DISTNAME=	heel-3.2.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/copiousfreetime/heel/
COMMENT=	Static file web server based on Rack and Thin
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-puma>=3.11.3:../../www/ruby-puma
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0<3:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.1<2:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=2.4<3:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.1<4:../../mail/ruby-mime-types

CONFLICTS+=	ruby[1-9][0-9][0-9]-heel-[0-9]* heel-[0-9]*

OVERRIDE_GEMSPEC+=	coderay>=0.8.260 launchy>=0.3.2 thin>=1.2 \
			puma>=3.11.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
