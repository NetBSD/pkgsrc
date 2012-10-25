# $NetBSD: Makefile,v 1.12 2012/10/25 06:56:57 asau Exp $

DISTNAME=	html-parser-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-html-parser-${VERSION}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	# http://www.jin.gr.jp/~nahi/Ruby/html-parser/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# http://www.jin.gr.jp/~nahi/Ruby/html-parser/README.html
COMMENT=	HTML-parser package for Ruby

NO_BUILD=	yes
NO_CONFIGURE=	yes

VERSION=		19990912p2
INSTALLATION_DIRS=	${RUBY_DOC}/html-parser ${RUBY_VENDORLIB}

SRCS=		formatter.rb html-parser.rb sgml-parser.rb

do-install:
.for f in ${SRCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.html \
		${DESTDIR}${PREFIX}/${RUBY_DOC}/html-parser

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
