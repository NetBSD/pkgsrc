# $NetBSD: Makefile,v 1.4 2003/12/24 06:39:33 taca Exp $

DISTNAME=	tag104
PKGNAME=	${RUBY_PKGNAMEPREFIX}tag-1.0.4
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.moonwolf.com/ruby/tag.html
COMMENT=	Ruby Simple HTML Tag library for CGI

EXTRACT_USING_PAX=	# defined

DIST_SUBDIR=	ruby
USE_RUBY_RD=	# defined
NO_CONFIGURE=	# defined

do-build:
	@cd ${WRKSRC}; ${RUBY_RD} tag.rb > tag.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/tag.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tag/ja
	${INSTALL_DATA} ${WRKSRC}/tag.html ${RUBY_DOCDIR}/tag/ja

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
