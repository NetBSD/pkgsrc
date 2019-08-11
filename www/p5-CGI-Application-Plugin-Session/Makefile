# $NetBSD: Makefile,v 1.6 2019/08/11 13:24:25 wiz Exp $
#

DISTNAME=	CGI-Application-Plugin-Session-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/F/FR/FREW/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://cpan.metacpan.org/authors/id/F/FR/FREW/
COMMENT=	Add CGI::Session support to CGI::Application
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CGI-Application>=4:../../www/p5-CGI-Application
DEPENDS+=	p5-CGI-Session>=0:../../www/p5-CGI-Session

PERL5_PACKLIST=		auto/CGI/Application/Plugin/Session/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
