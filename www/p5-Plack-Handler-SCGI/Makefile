# $NetBSD: Makefile,v 1.10 2017/06/05 14:25:28 ryoon Exp $

DISTNAME=	Plack-Handler-SCGI-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Handler-SCGI/
COMMENT=	PSGI handler on SCGI daemon
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Handler/SCGI/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Plack>=0.9901:../../www/p5-Plack
DEPENDS+=	p5-SCGI-[0-9]*:../../www/p5-SCGI
DEPENDS+=	p5-Try-Tiny>=0.04:../../devel/p5-Try-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
