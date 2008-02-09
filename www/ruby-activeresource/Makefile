# $NetBSD: Makefile,v 1.1.1.1 2008/02/09 06:27:48 minskim Exp $

DISTNAME=	activeresource-2.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/29357/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activeresource/
COMMENT=	Object-relational mapping for REST webservices

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.0.2:../../devel/ruby-activesupport

USE_LANGUAGES=	# none
NO_BUILD=	yes

.include "../../lang/ruby/modules.mk"

pre-install:
	${FIND} ${WRKSRC} -name \*.orig -exec ${RM} -f {} \;

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${RUBY_SITELIBDIR}/active_resource
	${FIND} ${RUBY_SITELIBDIR}/active_resource -type d		\
		-exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${RUBY_SITELIBDIR}/active_resource* -type f		\
		-exec ${CHMOD} ${LIBMODE} {} \;
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/active_resource
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG \
		${RUBY_DOCDIR}/active_resource
	${INSTALL_DATA} ${WRKSRC}/README \
		${RUBY_DOCDIR}/active_resource

.include "../../mk/bsd.pkg.mk"
