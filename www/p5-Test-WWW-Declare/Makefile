# $NetBSD: Makefile,v 1.13 2017/06/05 14:25:32 ryoon Exp $

DISTNAME=	Test-WWW-Declare-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Declare/
COMMENT=	Perl 5 module for declarative testing of web app
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/WWW/Declare/.packlist

BUILD_DEPENDS+=	p5-HTTP-Server-Simple-[0-9]*:../../www/p5-HTTP-Server-Simple
BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
