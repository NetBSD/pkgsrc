# $NetBSD: Makefile,v 1.10 2012/10/25 06:56:57 asau Exp $

DISTNAME=	htree-0.7
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.a-k-r.org/htree/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.a-k-r.org/htree/
COMMENT=	Tree data structure which represent HTML and XML data for Ruby
LICENSE=	ruby-license

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

INSTALL_TARGET=		--destdir=${DESTDIR}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${RUBY} -I. test-all.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
