# $NetBSD: Makefile,v 1.2 2003/03/29 12:42:54 jmmv Exp $

DISTNAME=	tag104
PKGNAME=	${RUBY_PKGNAMEPREFIX}tag-1.0.4
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.moonwolf.com/ruby/tag.html
COMMENT=	Ruby Simple HTML Tag library for CGI

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
