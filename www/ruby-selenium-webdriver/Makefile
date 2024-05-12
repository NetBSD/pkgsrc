# $NetBSD: Makefile,v 1.34 2024/05/12 16:35:31 taca Exp $

DISTNAME=	selenium-webdriver-4.20.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seleniumhq/selenium
COMMENT=	Tool for writing automated tests of websites
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.2.2:../../archivers/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-websocket>=1.0<2:../../www/ruby-websocket

USE_LANGUAGES=	# none

CHECK_SHLIBS_SKIP=	${GEM_LIBDIR}/bin/*

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
