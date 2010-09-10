# $NetBSD: Makefile,v 1.5 2010/09/10 08:22:56 taca Exp $

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-ruby-${MECAB_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES+=	ruby

COMMENT=	MeCab ruby module
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
REPLACE_RUBY+=		test.rb
USE_RUBY_EXTCONF=	yes

do-test:
	${RUN}								\
	cd ${WRKSRC};							\
	env ${TEST_ENV} ${RUBY} test.rb

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
