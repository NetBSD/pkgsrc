# $NetBSD: Makefile,v 1.6 2007/01/28 05:39:02 minskim Exp $

DISTNAME=	actionpack-1.13.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/16551/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ap.rubyonrails.com/
COMMENT=	Two-step approach to web response generation

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.4.0:../../devel/ruby-activesupport

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes
EXAMPLESDIR=		${RUBY_EXAMPLESDIR}/actionpack

REPLACE_RUBY+=	lib/action_controller/session/drb_server.rb
REPLACE_RUBY+=	examples/*.cgi examples/*.fcgi examples/*.rbx

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/replace.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/action_controller/support
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
