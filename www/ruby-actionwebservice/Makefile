# $NetBSD: Makefile,v 1.2 2005/09/04 14:17:34 taca Exp $

DISTNAME=	actionwebservice-0.8.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5173/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/aws/
COMMENT=	Simple support for publishing web service APIs for Rails

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack-[0-9]*:../../www/ruby-actionpack

USE_RUBY_SETUP=	yes

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/action_web_service
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/action_web_service
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP}				\
		${RUBY_EXAMPLESDIR}/action_web_service
	${FIND} ${RUBY_EXAMPLESDIR}/action_web_service -type d -print |	\
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${RUBY_EXAMPLESDIR}/action_web_service -type f -print |	\
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
