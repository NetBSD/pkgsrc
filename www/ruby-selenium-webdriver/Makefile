# $NetBSD: Makefile,v 1.13 2020/03/16 15:32:14 taca Exp $

DISTNAME=	selenium-webdriver-3.142.7
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seleniumhq/selenium
COMMENT=	Tool for writing automated tests of websites
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-childprocess>=0.5:../../sysutils/ruby-childprocess
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.2.2:../../archivers/ruby-zip

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+= \
	:files lib/selenium/webdriver/firefox/native/linux/amd64/x_ignore_nofocus.so= \
	lib/selenium/webdriver/firefox/native/linux/x86/x_ignore_nofocus.so=

#
# XXX: Remove this unportable garbage. Breaks on non-Linux targets.
pre-configure:
	${RM} ${WRKSRC}/lib/selenium/webdriver/firefox/native/linux/amd64/x_ignore_nofocus.so
	${RM} ${WRKSRC}/lib/selenium/webdriver/firefox/native/linux/x86/x_ignore_nofocus.so

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
