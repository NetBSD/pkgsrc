# $NetBSD: Makefile,v 1.1 2014/08/18 03:41:50 rodent Exp $

DISTNAME=	selenium-webdriver-2.42.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby www

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://selenium.googlecode.com/
COMMENT=	Tool for writing automated tests of websites
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-childprocess>=0.5.0:../../sysutils/ruby-childprocess
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2.0:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.0<2.0:../../archivers/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-websocket>=1.0.4:../../www/ruby-websocket

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	websocket>=1.0.4 # XXX: Will be fixed in the next rel.

post-install:
	# XXX: Remove this unportable garbage. Breaks on non-Linux targets.
	${RM} ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/lib/selenium/webdriver/firefox/native/linux/amd64/x_ignore_nofocus.${RUBY_DLEXT}
	${RM} ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/lib/selenium/webdriver/firefox/native/linux/x86/x_ignore_nofocus.${RUBY_DLEXT}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
