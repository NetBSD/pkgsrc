# $NetBSD: Makefile,v 1.3 2017/06/05 14:25:29 ryoon Exp $

DISTNAME=	Plack-Test-Agent-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Test-Agent/
COMMENT=	OO interface for testing low-level Plack/PSGI apps
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-URI>=0:../../www/p5-URI
#DEPENDS+=	p5-libwww>0:../../www/p5-libwww
DEPENDS+=	p5-Plack>=0.9913:../../www/p5-Plack
DEPENDS+=	p5-Modern-Perl-[0-9]*:../../devel/p5-Modern-Perl
DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-HTTP-Server-Simple-PSGI-[0-9]*:../../www/p5-HTTP-Server-Simple-PSGI
DEPENDS+=	p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle
#DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Test/Agent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
