# $NetBSD: Makefile,v 1.10 2004/03/16 02:01:11 taca Exp $
#

DISTNAME=	webrick-1.3.1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://www.webrick.org/src/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.webrick.org/
COMMENT=	Ruby library to build HTTP servers

DEPENDS+=	ruby-openssl>=0.1.3:../../security/ruby-openssl
DEPENDS+=	ruby-erb>=1.4.3:../../textproc/ruby-erb

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb
	${CP} -R ${WRKSRC}/doc ${RUBY_DOCDIR}/webrick
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/webrick

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
