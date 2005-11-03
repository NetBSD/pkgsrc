# $NetBSD: Makefile,v 1.8 2005/11/03 07:22:24 taca Exp $

DISTNAME=	webunit-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www textproc ruby
MASTER_SITES=	http://www.xpenguin.biz/download/webunit/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xpenguin.biz/download/webunit/index-en.html
COMMENT=	HTTP unit testing framework for Ruby

USE_RUBY_DIST_SUBDIR=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
WRKSRC=		${WRKDIR}/webunit
VERSION=	20040429++

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+= ${RUBY_PKGPREFIX}-html-parser>=19990912p1:../../textproc/ruby-html-parser
DEPENDS+= ${RUBY_PKGPREFIX}-htmlsplit>=1.0.2:../../www/ruby-htmlsplit

pre-patch:
	cd ${WRKSRC}/lib; \
		${RM} formatter.rb html-parser.rb sgml-parser.rb htmlsplit.rb

post-install:
	${CP} -R ${WRKSRC}/doc ${RUBY_DOCDIR}/webunit
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/webunit

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
