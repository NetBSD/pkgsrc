# $NetBSD: Makefile,v 1.1.1.1 2003/12/17 14:37:49 taca Exp $

DISTNAME=	webunit-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
WRKSRC= ${WRKDIR}/webunit
CATEGORIES=	www textproc
MASTER_SITES=	http://www.xpenguin.biz/download/webunit/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.xpenguin.biz/download/webunit/index-en.html
COMMENT=	HTTP unit testing framework for Ruby

VERSION=	20030121
DIST_SUBDIR=	ruby
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DEPENDS+=	ruby-testunit>=0.1:../../devel/ruby-testunit
DEPENDS+=	ruby-rexml>=2.4.8:../../textproc/ruby-rexml

post-install:
	${CP} -R ${WRKSRC}/doc ${RUBY_DOCDIR}/webunit
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/webunit

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
