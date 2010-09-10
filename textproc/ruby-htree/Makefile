# $NetBSD: Makefile,v 1.9 2010/09/10 08:14:55 taca Exp $

DISTNAME=	htree-0.7
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.a-k-r.org/htree/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.a-k-r.org/htree/
COMMENT=	Tree data structure which represent HTML and XML data for Ruby
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

INSTALL_TARGET=		--destdir=${DESTDIR}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${RUBY} -I. test-all.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
