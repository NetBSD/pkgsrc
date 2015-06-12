# $NetBSD: Makefile,v 1.10 2015/06/12 10:51:58 wiz Exp $

DISTNAME=	Continuity-1.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AW/AWWAIID/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Continuity/
COMMENT=	Perl 5 module to abstract statelessness of HTTP
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Continuity/.packlist

BUILD_DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-Event-[0-9]*:../../devel/p5-Event
DEPENDS+=	p5-Coro>=4.37:../../devel/p5-Coro
DEPENDS+=	p5-libwww>=1.36:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
