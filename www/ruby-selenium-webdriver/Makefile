# $NetBSD: Makefile,v 1.3 2015/03/13 17:59:44 taca Exp $

DISTNAME=	selenium-webdriver-2.45.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby www

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://selenium.googlecode.com/
COMMENT=	Tool for writing automated tests of websites
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-childprocess>=0.5.0:../../sysutils/ruby-childprocess
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2.0:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.0<2.0:../../archivers/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-websocket>=1.0<2:../../www/ruby-websocket

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+= \
	:files lib/selenium/webdriver/firefox/native/linux/amd64/x_ignore_nofocus.so= \
	lib/selenium/webdriver/firefox/native/linux/x86/x_ignore_nofocus.so=

#
# XXX: Remove this unportable garbage. Breaks on non-Linux targets.
pre-configure:
	${RM} ${WRKSRC}/lib/selenium/webdriver/firefox/native/linux/amd64/x_ignore_nofocus.${RUBY_DLEXT}
	${RM} ${WRKSRC}/lib/selenium/webdriver/firefox/native/linux/x86/x_ignore_nofocus.${RUBY_DLEXT}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
