# $NetBSD: Makefile,v 1.3 2005/11/02 14:48:39 taca Exp $

DISTNAME=	actionpack-1.10.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/6572/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ap.rubyonrails.com/
COMMENT=	Two-step approach to web response generation

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport-[0-9]*:../../devel/ruby-activesupport

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes
EXAMPLESDIR=		${RUBY_EXAMPLESDIR}/actionpack

post-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/action_controller/support
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/actionpack
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EXAMPLESDIR}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
