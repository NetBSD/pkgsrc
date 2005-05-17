# $NetBSD: Makefile,v 1.12 2005/05/17 22:15:54 jlam Exp $

DISTNAME=	tag104
PKGNAME=	${RUBY_PKGPREFIX}-tag-1.0.4
PKGREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.moonwolf.com/ruby/tag.html
COMMENT=	Ruby Simple HTML Tag library for CGI

# The distfile cannot be extracted with some tar (e.g. NetBSD 2.0)
# or some pax (e.g. NetBSD 1.6).  Force use of gtar instead.
#
EXTRACT_USING=	gtar

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

do-build:
	@cd ${WRKSRC}; ${RUBY_RD} tag.rb > tag.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/tag.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tag/ja
	${INSTALL_DATA} ${WRKSRC}/tag.html ${RUBY_DOCDIR}/tag/ja

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
