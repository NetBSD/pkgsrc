# $NetBSD: Makefile,v 1.6 2003/08/01 17:26:13 wiz Exp $
#

DISTNAME=	webrick-1.2.3
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.webrick.org/src/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.webrick.org
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
