# $NetBSD: Makefile,v 1.10 2017/06/05 14:25:28 ryoon Exp $

DISTNAME=	Plack-Handler-AnyEvent-ReverseHTTP-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Handler-AnyEvent-ReverseHTTP/
COMMENT=	Reversehttp gateway for PSGI application
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Handler/AnyEvent/ReverseHTTP/.packlist

DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
DEPENDS+=	p5-AnyEvent-ReverseHTTP-[0-9]*:../../www/p5-AnyEvent-ReverseHTTP
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Plack>=0.99:../../www/p5-Plack

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
