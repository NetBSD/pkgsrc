# $NetBSD: Makefile,v 1.2 2008/02/04 04:58:53 obache Exp $

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-ruby-${MECAB_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES+=	ruby

COMMENT=	MeCab ruby module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
REPLACE_RUBY+=		test.rb
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes

do-test:
	${RUN}								\
	cd ${WRKSRC};							\
	env ${TEST_ENV} ${RUBY} test.rb

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
