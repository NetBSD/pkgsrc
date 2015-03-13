# $NetBSD: Makefile,v 1.1 2015/03/13 16:34:26 taca Exp $

DISTNAME=	compass-import-once-1.0.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chriseppstein/compass/tree/master/import-once
COMMENT=	Speed up your Sass compilation by making @import file once
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass<3.5:../../www/ruby-sass

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
