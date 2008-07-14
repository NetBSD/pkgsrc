# $NetBSD: Makefile,v 1.17 2008/07/14 12:56:14 joerg Exp $

DISTNAME=	tag104
PKGNAME=	${RUBY_PKGPREFIX}-tag-1.0.4
PKGREVISION=	3
CATEGORIES=	www ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.moonwolf.com/ruby/tag.html
COMMENT=	Ruby Simple HTML Tag library for CGI

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_USING=	bsdtar

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	${RUBY_VENDORLIB} ${RUBY_DOC}/tag/ja

do-build:
	@cd ${WRKSRC}; ${RUBY_RD} tag.rb > tag.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/tag.rb ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}
	${INSTALL_DATA} ${WRKSRC}/tag.html ${DESTDIR}${PREFIX}/${RUBY_DOC}/tag/ja

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
