# $NetBSD: Makefile,v 1.1.1.1 2003/07/06 15:49:13 taca Exp $

DISTNAME=	borges-0.2.0
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://segment7.net/ruby-code/borges/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://segment7.net/ruby-code/borges/borges.html
COMMENT=	Ruby web appliation framework

DEPENDS+=	ruby-installpkg:../../devel/ruby-installpkg
DEPENDS+=	ruby-webrick:../../www/ruby-webrick

USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
