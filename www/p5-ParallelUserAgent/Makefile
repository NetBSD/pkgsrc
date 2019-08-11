# $NetBSD: Makefile,v 1.15 2019/08/11 13:24:55 wiz Exp $
#

DISTNAME=	ParallelUserAgent-2.62
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}
MASTER_SITES=  	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSOUTH/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ParallelUserAgent
COMMENT=	CPAN Bundle for the LWP Parallel User Agent extension
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Parallel/.packlist

EXTRACT_USING=	gtar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
