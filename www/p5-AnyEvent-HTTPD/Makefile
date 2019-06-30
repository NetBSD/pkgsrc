# $NetBSD: Makefile,v 1.15 2019/06/30 20:17:19 nia Exp $

DISTNAME=	AnyEvent-HTTPD-0.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AnyEvent-HTTPD
COMMENT=	Perl 5 simple lightweight event based web (application) server
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/AnyEvent/HTTPD/.packlist

DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
DEPENDS+=	p5-Object-Event-[0-9]*:../../devel/p5-Object-Event
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
#DEPENDS+=	{perl>=5,p5-Time-Local-[0-9]*}:../../time/p5-Time-Local
DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense
DEPENDS+=	p5-AnyEvent-HTTP-[0-9]*:../../www/p5-AnyEvent-HTTP

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
