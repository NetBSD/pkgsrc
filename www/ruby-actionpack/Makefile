# $NetBSD: Makefile,v 1.11 2008/02/09 06:23:29 minskim Exp $

DISTNAME=	actionpack-2.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/29351/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/actionpack/
COMMENT=	Two-step approach to web response generation

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.0.2:../../devel/ruby-activesupport

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

REPLACE_RUBY+=	lib/action_controller/session/drb_server.rb

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/replace.mk"

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/lib/action_controller/templates/rescues/* \
		${RUBY_SITELIBDIR}/action_controller/templates/rescues
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/actionpack

.include "../../mk/bsd.pkg.mk"
