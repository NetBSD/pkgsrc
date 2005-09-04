# $NetBSD: Makefile,v 1.2 2005/09/04 14:05:44 taca Exp $

DISTNAME=	actionpack-1.9.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5167/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ap.rubyonrails.com/
COMMENT=	Two-step approach to web response generation

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport-[0-9]*:../../devel/ruby-activesupport

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/action_controller/support
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/actionpack

.include "../../mk/bsd.pkg.mk"
