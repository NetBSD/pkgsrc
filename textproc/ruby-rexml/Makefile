# $NetBSD: Makefile,v 1.1.1.1 2003/04/26 16:16:51 taca Exp $
#

DISTNAME=	rexml_2.4.8
PKGNAME=	${RUBY_PKGNAMEPREFIX}rexml-2.4.8
WRKSRC=		${WRKDIR}/rexml
CATEGORIES=	textproc
MASTER_SITES=	http://www.germane-software.com/archives/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.germane-software.com/software/rexml/
COMMENT=	Pure Ruby XML parser based on Java Electric XML

USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC}; ${RUBY} bin/install.rb
	${CP} -r ${WRKDIR}/rexml/docs ${RUBY_DOCDIR}/rexml
	${CP} -r ${WRKDIR}/rexml/doc ${RUBY_DOCDIR}/rexml/api
	${CHMOD} -R -w ${RUBY_DOCDIR}/rexml

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
