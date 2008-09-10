# $NetBSD: Makefile,v 1.1.1.1 2008/09/10 23:26:13 seb Exp $
#

DISTNAME=	Test-WWW-Declare-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Declare/
COMMENT=	Perl 5 module for declarative testing of web app

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/WWW/Declare/.packlist

BUILD_DEPENDS+=	p5-HTTP-Server-Simple-[0-9]*:../../www/p5-HTTP-Server-Simple
BUILD_DEPENDS+=	p5-Test-Tester-[0-9]*:../../devel/p5-Test-Tester
DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
