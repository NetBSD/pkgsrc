# $NetBSD: Makefile,v 1.20 2024/03/04 15:23:34 taca Exp $

DISTNAME=	heel-4.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/copiousfreetime/heel/
COMMENT=	Static file web server based on Rack and Thin
LICENSE=	modified-bsd

#DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.0<4:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rackup>=2.1<3:../../www/ruby-rackup
DEPENDS+=	${RUBY_PKGPREFIX}-puma>=6.0<7:../../www/ruby-puma
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.4<4:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=2.5<3:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=4.0<5:../../www/ruby-rouge

CONFLICTS+=	ruby[1-9][0-9][0-9]-heel-[0-9]* heel-[0-9]*

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
