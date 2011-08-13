# $NetBSD: Makefile,v 1.5 2011/08/13 00:29:32 taca Exp $

DISTNAME=	mechanize-2.0.1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mechanize.rubyforge.org/
COMMENT=	Library to automate interaction with websites
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.4<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=1.8<2:../../www/ruby-net-http-persistent
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-digest_auth>=1.1<2:../../www/ruby-net-http-digest_auth
DEPENDS+=	${RUBY_PKGPREFIX}-webrobots>=0.0<1:../../www/ruby-webrobots

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
