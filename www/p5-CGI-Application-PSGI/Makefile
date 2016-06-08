# $NetBSD: Makefile,v 1.9 2016/06/08 19:24:55 wiz Exp $

DISTNAME=	CGI-Application-PSGI-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Application-PSGI/
COMMENT=	Perl 5 module PSGI adapter for CGI::Application
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/CGI/Application/PSGI/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=	p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application
DEPENDS+=	p5-CGI-PSGI-[0-9]*:../../www/p5-CGI-PSGI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
