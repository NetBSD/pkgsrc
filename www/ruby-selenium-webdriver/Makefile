# $NetBSD: Makefile,v 1.19 2022/12/04 16:29:26 taca Exp $

DISTNAME=	selenium-webdriver-4.7.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seleniumhq/selenium
COMMENT=	Tool for writing automated tests of websites
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-childprocess>=0.5:../../sysutils/ruby-childprocess
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.2.2:../../archivers/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-websocket>=1.0<2:../../www/ruby-websocket

USE_LANGUAGES=	# none

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} == "27"
DEPENDS+=	${RUBY_PKGPREFIX}-rexml>=3.2<4:../../textproc/ruby-rexml
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
