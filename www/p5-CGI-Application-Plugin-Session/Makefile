# $NetBSD: Makefile,v 1.8 2020/09/08 13:10:00 wiz Exp $

DISTNAME=	CGI-Application-Plugin-Session-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/F/FR/FREW/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/CGI::Application::Plugin::Session
COMMENT=	Add CGI::Session support to CGI::Application
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CGI-Application>=4:../../www/p5-CGI-Application
DEPENDS+=	p5-CGI-Session>=0:../../www/p5-CGI-Session

PERL5_PACKLIST=		auto/CGI/Application/Plugin/Session/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
