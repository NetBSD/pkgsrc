# $NetBSD: Makefile,v 1.2 2003/07/07 03:42:01 taca Exp $
#

DISTNAME=	webrick-1.2.3
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://www.webrick.org/src/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.webrick.org
COMMENT=	Ruby library to build HTTP servers

DEPENDS+=	ruby-openssl:../../security/ruby-openssl
DEPENDS+=	ruby-erb:../../textproc/ruby-erb

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb
	${CP} -R ${WRKSRC}/doc ${RUBY_DOCDIR}/webrick
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/webrick

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
