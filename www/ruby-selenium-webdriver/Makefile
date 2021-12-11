# $NetBSD: Makefile,v 1.14 2021/12/11 15:50:00 taca Exp $

DISTNAME=	selenium-webdriver-4.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seleniumhq/selenium
COMMENT=	Tool for writing automated tests of websites
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-childprocess>=0.5:../../sysutils/ruby-childprocess
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.2.2:../../archivers/ruby-zip

USE_LANGUAGES=	# none

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} == "26" || ${RUBY_VER} == "27"
DEPENDS+=	${RUBY_PKGPREFIX}-rexml>=0:../../textproc/ruby-rexml
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
