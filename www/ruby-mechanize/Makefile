# $NetBSD: Makefile,v 1.12 2014/04/28 21:57:46 joerg Exp $

DISTNAME=	mechanize-2.7.2
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mechanize.rubyforge.org/
COMMENT=	Library to automate interaction with websites
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-http-digest_auth>=1.1.1:../../www/ruby-net-http-digest_auth
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=2.5.2:../../www/ruby-net-http-persistent
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.17.2:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-domain_name>=0.5<1:../../net/ruby-domain_name
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0.0<1.1:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.4<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-ntlm-http>=0.1<1:../../www/ruby-ntlm-http
DEPENDS+=	${RUBY_PKGPREFIX}-webrobots>=0.0<0.2:../../www/ruby-webrobots

RUBY_VERSION_SUPPORTED=	200 193 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
