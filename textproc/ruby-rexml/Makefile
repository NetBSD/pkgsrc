# $NetBSD: Makefile,v 1.3 2004/03/16 02:01:11 taca Exp $
#

DISTNAME=	rexml_2.4.8
PKGNAME=	${RUBY_PKGNAMEPREFIX}rexml-2.4.8
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.germane-software.com/archives/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.germane-software.com/software/rexml/
COMMENT=	Pure Ruby XML parser based on Java Electric XML

WRKSRC=		${WRKDIR}/rexml
USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC}; ${RUBY} bin/install.rb
	${CP} -r ${WRKDIR}/rexml/docs ${RUBY_DOCDIR}/rexml
	${CP} -r ${WRKDIR}/rexml/doc ${RUBY_DOCDIR}/rexml/api
	${CHMOD} -R -w ${RUBY_DOCDIR}/rexml

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
