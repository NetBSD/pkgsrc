# $NetBSD: Makefile,v 1.7 2012/03/01 01:24:48 minskim Exp $

DISTNAME=	mechanize-2.3
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mechanize.rubyforge.org/
COMMENT=	Library to automate interaction with websites
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-domain_name>=0.5.1:../../net/ruby-domain_name
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.17:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-digest_auth>=1.1<2:../../www/ruby-net-http-digest_auth
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=2.5:../../www/ruby-net-http-persistent
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.4<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-ntlm-http>=0.1.1:../../www/ruby-ntlm-http
DEPENDS+=	${RUBY_PKGPREFIX}-webrobots>=0.0<1:../../www/ruby-webrobots

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
