# $NetBSD: Makefile,v 1.2 2019/02/24 16:26:21 taca Exp $

DISTNAME=	compass-import-once-1.0.5
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chriseppstein/compass/tree/master/import-once
COMMENT=	Speed up your Sass compilation by making @import file once
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass34<3.5:../../www/ruby-sass34

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
