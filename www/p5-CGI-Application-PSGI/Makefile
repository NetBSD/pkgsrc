# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:44 obache Exp $

DISTNAME=	CGI-Application-PSGI-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Application-PSGI/
COMMENT=	Perl 5 module PSGI adapter for CGI::Application
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/CGI/Application/PSGI/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=	p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application
DEPENDS+=	p5-CGI-PSGI-[0-9]*:../../www/p5-CGI-PSGI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
