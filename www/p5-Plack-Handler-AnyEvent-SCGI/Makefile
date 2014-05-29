# $NetBSD: Makefile,v 1.7 2014/05/29 23:38:12 wiz Exp $

DISTNAME=	Plack-Handler-AnyEvent-SCGI-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Handler-AnyEvent-SCGI/
COMMENT=	PSGI handler on AnyEvent::SCGI
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Handler/AnyEvent/SCGI/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-AnyEvent-SCGI-[0-9]*:../../www/p5-AnyEvent-SCGI
DEPENDS+=	p5-Plack>=0.9901:../../www/p5-Plack

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
