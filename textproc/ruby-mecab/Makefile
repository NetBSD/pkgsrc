# $NetBSD: Makefile,v 1.8 2012/10/25 06:56:57 asau Exp $

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-ruby-${MECAB_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES+=	ruby

COMMENT=	MeCab ruby module
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

USE_LANGUAGES=	c c++
REPLACE_RUBY+=		test.rb
USE_RUBY_EXTCONF=	yes

do-test:
	${RUN}								\
	cd ${WRKSRC};							\
	${SETENV} ${TEST_ENV} ${RUBY} -I${WRKSRC} test.rb

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
