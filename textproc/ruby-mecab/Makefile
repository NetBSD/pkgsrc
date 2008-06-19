# $NetBSD: Makefile,v 1.3 2008/06/19 14:56:39 taca Exp $

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-ruby-${MECAB_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-mecab-${MECAB_VERSION}
PKGREVISION=	1
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
