# $NetBSD: Makefile,v 1.1.1.1 2010/12/26 15:21:40 taca Exp $

DISTNAME=	rails-2.3.10
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Framework for developing database-backed web applications
LICENSE=	mit

.include "../../lang/ruby/gem.mk"

.if ${RUBY_VER} == "18"
DEPENDS+=	${RUBY_PKGPREFIX}-rake>=0.8.3:../../devel/rake
.endif
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.10<3.0.0:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.3.10<3.0.0:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=2.3.10<3.0.0:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-actionmailer>=2.3.10<3.0.0:../../mail/ruby-actionmailer
DEPENDS+=	${RUBY_PKGPREFIX}-activeresource>=2.3.10<3.0.0:../../www/ruby-activeresource

CONFLICTS+=	ruby[1-9][0-9]-rails-[0-9]* rails-[0-9]*

REPLACE_RUBY_DIRS=	bin
REPLACE_RUBY_PAT=	*

pre-configure:
	${RM} -f ${WRKSRC}/railties-3.0.0.beta3.gem

.include "../../mk/bsd.pkg.mk"
