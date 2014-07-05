# $NetBSD: Makefile,v 1.1 2014/07/05 12:33:15 rodent Exp $

DISTNAME=	yard-0.8.7.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby textproc

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://yardoc.org/
COMMENT=	Documentation generation tool for the Ruby programming language
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	mv ${DESTDIR}${PREFIX}/bin/yard \
		${DESTDIR}${PREFIX}/bin/yard${RUBY_SUFFIX}
	mv ${DESTDIR}${PREFIX}/bin/yardoc \
		${DESTDIR}${PREFIX}/bin/yardoc${RUBY_SUFFIX}
	mv ${DESTDIR}${PREFIX}/bin/yri \
		${DESTDIR}${PREFIX}/bin/yri${RUBY_SUFFIX}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
