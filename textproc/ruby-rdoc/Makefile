# $NetBSD: Makefile,v 1.4 2005/03/06 17:19:07 taca Exp $
#

DISTNAME=	rdoc-beta-2
PKGNAME=	${RUBY_PKGPREFIX}-rdoc-0.0.0.2
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rdoc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://rdoc.sourceforge.net/
COMMENT=	Generates structured HTML documentation from Ruby source

RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_INSTALL=	yes
NO_BUILD=		yes
NO_CONFIGURE=		yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
