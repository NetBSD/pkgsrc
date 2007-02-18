# $NetBSD: Makefile,v 1.6 2007/02/18 23:35:42 minskim Exp $

DISTNAME=	actionwebservice-1.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/17233/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/aws/
COMMENT=	Simple support for publishing web service APIs for Rails

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=1.13.2:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=1.15.2:../../databases/ruby-activerecord

USE_RUBY_SETUP=	yes

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/lib/action_web_service/templates/scaffolds/* \
		${RUBY_SITELIBDIR}/action_web_service/templates/scaffolds
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/action_web_service
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/action_web_service
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/action_web_service
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/action_web_service
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/action_web_service
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP}				\
		${RUBY_EXAMPLESDIR}/action_web_service
	${FIND} ${RUBY_EXAMPLESDIR}/action_web_service -type d -print |	\
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${RUBY_EXAMPLESDIR}/action_web_service -type f -print |	\
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
