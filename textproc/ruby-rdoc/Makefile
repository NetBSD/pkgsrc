# $NetBSD: Makefile,v 1.1.1.1 2003/02/16 02:03:33 salo Exp $
#

DISTNAME=	rdoc-beta-2
PKGNAME=	ruby-rdoc-0.0.0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rdoc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://rdoc.sourceforge.net/
COMMENT=	Generates structured HTML documentation from Ruby source

NO_BUILD=	YES
USE_RUBY=	YES

do-install:
		cd ${WRKSRC} && ${RUBY} install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
