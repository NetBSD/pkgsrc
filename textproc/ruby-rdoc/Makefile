# $NetBSD: Makefile,v 1.2 2004/03/16 02:01:11 taca Exp $
#

DISTNAME=	rdoc-beta-2
PKGNAME=	ruby-rdoc-0.0.0.2
CATEGORIES=	textproc ruby
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
