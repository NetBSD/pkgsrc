# $NetBSD: Makefile,v 1.7 2019/08/11 13:24:56 wiz Exp $

DISTNAME=	Plack-Middleware-FixMissingBodyInRedirect-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Middleware-FixMissingBodyInRedirect
COMMENT=	Sets body for redirect response, if it's not already set
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Middleware/FixMissingBodyInRedirect/.packlist

DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
