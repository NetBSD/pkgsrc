# $NetBSD: Makefile,v 1.10 2012/10/28 06:31:03 asau Exp $

DISTNAME=	mechanize-2.5.1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mechanize.rubyforge.org/
COMMENT=	Library to automate interaction with websites
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-domain_name>=0.5<1:../../net/ruby-domain_name
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.17<2:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-digest_auth>=1.1<2:../../www/ruby-net-http-digest_auth
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=2.5<3:../../www/ruby-net-http-persistent
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.4<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-ntlm-http>=0.1<1:../../www/ruby-ntlm-http
DEPENDS+=	${RUBY_PKGPREFIX}-webrobots>=0.0<1:../../www/ruby-webrobots

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
