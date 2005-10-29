# $NetBSD: Makefile,v 1.16 2005/10/29 12:02:23 wiz Exp $
#

DISTNAME=	webrick-1.3.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www ruby
MASTER_SITES=	http://www.webrick.org/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.webrick.org/
COMMENT=	Ruby library to build HTTP servers

DEPENDS+=	${RUBY_PKGPREFIX}-openssl>=0.1.3:../../security/ruby16-openssl
DEPENDS+=	${RUBY_PKGPREFIX}-erb>=1.4.3:../../textproc/ruby-erb

RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_INSTALL=	yes
NO_BUILD=		yes
NO_CONFIGURE=		yes

post-install:
	${CP} -R ${WRKSRC}/doc ${RUBY_DOCDIR}/webrick
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/webrick

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
